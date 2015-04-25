#!/bin/sh
# R2pkg
#
# Copyright (c) 2014,2015
#	Brook Milligan.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the author nor the names of any contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
#
# Create an R package in the current directory
#
NAME="R2pkg"
VERS="@VERS@"

USAGE="${NAME} [-DVehqv] [-E editor] [package] -- create an R package for pkgsrc"

: ${CRAN_URL:=ftp://cran.r-project.org}
: ${PKGEDITOR:=${EDITOR:=vi}}

# Substituted by pkgsrc at pre-configure time.
MAKE=@MAKE@
ECHO=echo
EDIT=1
QUIET=0
VERBOSE=0

while getopts DE:Vehqv f
do
    case $f in
	D) DESCRIPTION=yes;;
	E) PKGEDITOR=${OPTARG};;
	V) echo "${NAME} v${VERS}"; exit 0;;
	e) EDIT=0;;
	h) echo ${USAGE}; exit 0;;
	q) ECHO=":"; QUIET=1;;
	v) VERBOSE=$((${VERBOSE}+1));;
        \?) echo ${USAGE}; exit 1;;
    esac
done
shift `expr ${OPTIND} - 1`

if [ ${#} -eq 0 ]; then
    read -p "package: " RPKG TAIL
    if [ "X${TAIL}" != "X" ]; then
	echo "Error: multiple package names given."
	echo ${USAGE}
	exit 1
    fi
elif [ ${#} -eq 1 ]; then
    RPKG=${1}
else
    echo ${USAGE}
    exit 1
fi

if [ ${VERBOSE} -eq 0 ]; then
    STDOUT=">/dev/null 2>&1"
    STDOUT2=">/dev/null 2>&1"
elif [ ${VERBOSE} -eq 1 ]; then
    STDOUT=""
    STDOUT2=">/dev/null 2>&1"
else
    STDOUT=""
    STDOUT2=""
fi

CRAN_PACKAGES=pub/R/web/packages
RPKG_DESCRIPTION_URL=${CRAN_URL}/${CRAN_PACKAGES}/${RPKG}/DESCRIPTION

check_for_R ()
{
    R_CMD="R --no-save ${STDOUT2}"
    echo "q()" | eval ${R_CMD}
    if [ ${?} -ne 0 ]; then
	echo "ERROR: math/R package is not installed."
	exit 1
    fi
}

preserve_original_files ()
{
    [ -f DESCR ]    && mv DESCR DESCR.orig
    [ -f Makefile ] && mv Makefile Makefile.orig
    [ -f distinfo ] && mv distinfo distinfo.orig
}

make_package ()
{
    R_CMD="R --no-save ${STDOUT2}"
    [ "X${DESCRIPTION}" != "X" ] && DESCRIPTION_CMD="copy.description(connection)"
    cat << EOF | eval ${R_CMD}
one.line <- function(s) gsub(' *\n *',' ',s)
pkg.vers <- function(s) gsub('_','.',s)
field <- function(key,value) paste(key,'=\t',value,sep='')

licenses <- list()
licenses[['ACM']]           <- 'acm-license'
licenses[['APACHE']]        <- 'apache-2.0'
licenses[['ARTISTIC']]      <- 'artistic-2.0'
licenses[['BSD-2']]         <- '2-clause-bsd'
licenses[['GPL-2']]         <- 'gnu-gpl-v2'
licenses[['GPL-3']]         <- 'gnu-gpl-v3'
licenses[['GPL (>= 2)']]    <- 'gnu-gpl-v2'
licenses[['GPL-2 | GPL-3']] <- 'gnu-gpl-v2 OR gnu-gpl-v3'
licenses[['LGPL-2']]        <- 'gnu-lgpl-v2'
licenses[['LGPL-2.1']]      <- 'gnu-lgpl-v2.1'
licenses[['LGPL (>= 2)']]   <- 'gnu-lgpl-v2'
licenses[['LUCENT']]        <- 'lucent'
licenses[['MIT']]           <- 'mit'
licenses[['POSTGRESQL']]    <- 'postgresql-license'

paste2 <- function(s1,s2)
{
  if (is.na(s1) && is.na(s2)) return ('')
  if (is.na(s1) && !is.na(s2)) return (s2)
  if (!is.na(s1) && is.na(s2)) return (s1)
  if (!is.na(s1) && !is.na(s2)) return (paste(s1,s2))
}

todo.license <- function(s)
{
  if (is.null(licenses[[s]]))
    todo <- '# TODO: LICENSE'
  else
    todo <- 'LICENSE'
  todo
}

pkgsrc.license <- function(s)
{
  license <- licenses[[s]]
  if (is.null(license))
    license <- s
  license
}

package <- function(s) field('R_PKGNAME',one.line(s))
version <- function(s) field('R_PKGVER',one.line(s))
comment <- function(s) field('COMMENT',one.line(s))
license <- function(s) field(todo.license(s),pkgsrc.license(s))

categories <- function() paste('CATEGORIES=',paste(basename(dirname(getwd())),'R'),sep='	')
description <- function(s) strwrap(s,width=71)

depends <- function(s1,s2)
{
  s <- paste2(s1,s2)
  imports <- na.omit(strsplit(one.line(s),', *')[[1]])
  DEPENDS <- ''
  if (length(imports) > 0)
    {
      for (i in 1:length(imports))
        {
          dependency <- strsplit(imports[i],' *\\\\( *')[[1]]
          depends <- dependency[1]
          depends.vers <- ifelse(length(dependency) == 2, dependency[2], '>=???')
          depends.vers <- gsub(' ','',depends.vers)
          depends.vers <- pkg.vers(gsub('\\\\)','',depends.vers))
          depends.line <- paste('# DEPENDS+=\tR-',depends,depends.vers,':../../CATEGORY/R-',depends,sep='')
          DEPENDS <- paste(DEPENDS,depends.line,sep='\n')
        }
      DEPENDS <- paste(DEPENDS,'',sep='\n')
    }
  DEPENDS
}

copy.description <- function(connection)
{
  description <- readLines(connection)
  writeLines(description,con='DESCRIPTION')
}

connection <- url('${RPKG_DESCRIPTION_URL}')
${DESCRIPTION_CMD}
metadata <- read.dcf(connection, fields=c('Package','Version','Title','Description','License','Imports','Depends'))

CVS          <- '# \$NetBSD\$'
CATEGORIES   <- categories()
MASTER.SITES <- 'MASTER_SITES=	\${MASTER_SITE_R_CRAN:=contrib/}'
MAINTAINER   <- 'MAINTAINER=	pkgsrc-users@NetBSD.org'
HOMEPAGE     <- 'HOMEPAGE=	\${R_HOMEPAGE_BASE}/${RPKG}/'
COMMENT      <- comment(metadata[3])
LICENSE      <- license(metadata[5])
R_PKGNAME    <- package(metadata[1])
R_PKGVER     <- version(metadata[2])
DEPENDS      <- depends(metadata[6],metadata[7])
INCLUDE.R    <- '.include "../../math/R/Makefile.extension"'
INCLUDE.PKG  <- '.include "../../mk/bsd.pkg.mk"'

DESCR        <- description(metadata[4])

Makefile <- paste(CVS,
                  '',
                  CATEGORIES,
                  MASTER.SITES,
                  '',
                  MAINTAINER,
                  HOMEPAGE,
                  COMMENT,
                  LICENSE,
                  '',
                  R_PKGNAME,
                  R_PKGVER,
                  DEPENDS,
                  INCLUDE.R,
                  INCLUDE.PKG,
                  sep='\n')

write(Makefile,'Makefile')
write(DESCR,'DESCR')
EOF
    if [ ${?} -ne 0 ]; then
	echo "ERROR: parsing metadata failed."
	exit 1
    fi
}

edit_Makefile ()
{
    [ ${EDIT} -eq 0 ] || ${PKGEDITOR} Makefile
}

edit_DESCR ()
{
    [ ${EDIT} -eq 0 ] || ${PKGEDITOR} DESCR
}

create_distinfo ()
{
    ${ECHO} "Fetching package ... "
    MAKE_CMD="${MAKE} makesum ${STDOUT}"
    eval ${MAKE_CMD}
}

extract ()
{
    ${ECHO} "Extracting package ... "
    MAKE_CMD="${MAKE} extract ${STDOUT}"
    eval ${MAKE_CMD}
}

cleanup ()
{
    if [ -f DESCR.orig ] && cmp -s DESCR.orig DESCR; then
	mv DESCR.orig DESCR
    fi
    if [ -f Makefile.orig ] && cmp -s Makefile.orig Makefile; then
	mv Makefile.orig Makefile
    fi
    if [ -f distinfo.orig ] && cmp -s distinfo.orig distinfo; then
	mv distinfo.orig distinfo
    fi
}

messages ()
{
    if [ ${QUIET} -eq 0 ]; then
	cat << EOF
Please do not forget the following:
- check DESCR and edit as necessary.
- check Makefile:
  o verify the COMMENT.
  o verify the LICENSE.
  o verify the DEPENDS, especially the categories.
EOF
	[ "X${DESCRIPTION}" != "X" ] && echo "- remove DESCRIPTION."
    fi
}

${ECHO} "Creating R package: ${RPKG} ... "
check_for_R
preserve_original_files
make_package
edit_Makefile
edit_DESCR
create_distinfo
extract
cleanup
messages
