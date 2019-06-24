#!/bin/sh
# $NetBSD: R2pkg.sh,v 1.4 2019/06/24 13:46:04 brook Exp $
#
# Copyright (c) 2014,2015,2016,2017,2018,2019
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

R2PKG=${0}

USAGE="${NAME} [-DVehqrv] [-E editor] [-M maintainer] [-R dependency_file] [package] -- create an R package for pkgsrc"

: ${CRAN_URL:=ftp://cran.r-project.org}
: ${PKGEDITOR:=${EDITOR:=vi}}

# Substituted by pkgsrc at pre-configure time.
MAKE=@MAKE@
EDIT=1
MAINTAINER_EMAIL=pkgsrc-users@NetBSD.org
QUIET=0
RECURSIVE=0
TOP_LEVEL=1
UPDATE=0
VERBOSE=0

DESCRIPTION_CONNECTION=connection

while getopts DE:M:R:Vehqruv f
do
    case $f in
	D) DESCRIPTION=yes; DESCRIPTION_CONNECTION="'DESCRIPTION'"; ARGS="${ARGS} -D";;
	E) PKGEDITOR=${OPTARG}; ARGS="${ARGS} -E ${PKGEDITOR}";;
	M) MAINTAINER_EMAIL=${OPTARG}; ARGS="${ARGS} -M ${MAINTAINER_EMAIL}";;
	R) DEPENDENCY_LIST=${OPTARG}; RECURSIVE=1; TOP_LEVEL=0; ARGS="${ARGS} -R ${DEPENDENCY_LIST}";;
	V) echo "${NAME} v${VERS}"; exit 0;;
	e) EDIT=0; ARGS="${ARGS} -e";;
	h) echo ${USAGE}; exit 0;;
	q) QUIET=1; ARGS="${ARGS} -q";;
	r) RECURSIVE=1; RECURSIVE_MESSAGE=1; ARGS="${ARGS} -r";;
	u) UPDATE=1; ARGS="${ARGS} -u";;
	v) VERBOSE=$((${VERBOSE}+1)); ARGS="${ARGS} -v";;
        \?) echo ${USAGE}; exit 1;;
    esac
done
shift `expr ${OPTIND} - 1`

if [ ${UPDATE} -eq 1 ]; then
    RPKG=$(echo $(basename $(pwd)) | sed -e 's/^R-//');
elif [ ${#} -eq 0 ]; then
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

R_FILE=${TMPDIR}/R2pkg.$$.R

if [ ${TOP_LEVEL} -eq 1 ]; then
    BANNER_MSG="===> Creating R package: R-${RPKG}"
else
    BANNER_MSG="===> Creating dependency package: R-${RPKG}"
fi
if [ "X${DEPENDENCY_LIST}" = "X" ]; then
    DEPENDENCY_LIST=${TMPDIR}/R2pkg.depends.$$
    ARGS="${ARGS} -R ${DEPENDENCY_LIST}"
fi
if [ ${QUIET} -eq 1 ]; then
    STDOUT_MAKESUM=">/dev/null"
    STDOUT_EXTRACT=">/dev/null"
    QUIET_CURL="TRUE"
    ECHO_BANNER=":"
    ECHO_DONE=":"
    ECHO_FETCH=":"
    ECHO_EXTRACT=":"
    if [ ${TOP_LEVEL} -eq 0 ]; then
	ECHO=":"
    fi
elif [ ${VERBOSE} -eq 0 ]; then
    STDOUT_MAKESUM=">/dev/null"
    STDOUT_EXTRACT=">/dev/null"
    QUIET_CURL="TRUE"
    ECHO_BANNER="echo"
    ECHO_DONE=":"
    ECHO_FETCH=":"
    ECHO_EXTRACT="echo"
elif [ ${VERBOSE} -eq 1 ]; then
    STDOUT_MAKESUM=">/dev/null"
    STDOUT_EXTRACT=">/dev/null"
    QUIET_CURL="TRUE"
    ECHO_BANNER="echo"
    ECHO_DONE="echo"
    ECHO_FETCH="echo"
    ECHO_EXTRACT="echo"
else
    STDOUT_MAKESUM=""
    STDOUT_EXTRACT=""
    QUIET_CURL="FALSE"
    ECHO_BANNER="echo"
    ECHO_DONE="echo"
    ECHO_FETCH="echo"
    ECHO_EXTRACT="echo"
fi

CRAN_PACKAGES=pub/R/web/packages
RPKG_DESCRIPTION_URL=${CRAN_URL}/${CRAN_PACKAGES}/${RPKG}/DESCRIPTION

check_for_R ()
{
    R_CMD="Rscript --no-save /dev/null"
    eval ${R_CMD}
    if [ ${?} -ne 0 ]; then
	echo "ERROR: math/R package is not installed."
	exit 1
    fi
}

preserve_original_files ()
{
    [ -f DESCR ]    && mv DESCR DESCR.orig
    [ -f Makefile ] && grep -e "MAINTAINER=" Makefile > MAINTAINER
    [ -f Makefile ] && mv Makefile Makefile.orig
    [ -f distinfo ] && mv distinfo distinfo.orig
}

make_package ()
{
    R_CMD="Rscript --no-save ${R_FILE}"
    cat << EOF > ${R_FILE}
trim.space <- function(s) gsub('[[:space:]]','',s)
trim.blank <- function(s) gsub('[[:blank:]]','',s)
one.space <- function(s) gsub('[[:blank:]]+',' ',s)
one.line <- function(s) gsub('\n',' ',s)
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
maintainer <- function(email)
  {
     if (file.exists('MAINTAINER'))
       {
         x <- scan('MAINTAINER','character',quiet=TRUE)
         if (length(x) == 2)
           email = x[2]
         else
           message('WARNING: previous MAINTAINER is ignored')
       }
     email <- paste0('MAINTAINER=	',email)
     email
   }

categories <- function() paste('CATEGORIES=',paste(basename(dirname(getwd())),'R'),sep='	')
description <- function(s) strwrap(s,width=71)

filter.imports <- function(s)
{
  base.packages <- c('R','MASS','Matrix','Rcpp','cluster','grDevices','graphics','grid','foreign','lattice','nlme','methods','nnet','parallel','rpart','stats','survival','tools','utils')
  for (pkg in base.packages)
    {
      re.pkg <- paste('^',pkg,sep='')
      s <- s[!grepl(re.pkg,s)]
    }
  s
}

make.imports <- function(s1,s2)
{
  s <- paste2(s1,s2)
  s <- gsub('([[:alnum:]]+)[[:blank:]]+(\\\([^\\\)]*\\\))?[[:blank:]]*,?','\\\\1 \\\\2,',s)
  imports <- na.omit(unlist(strsplit(s,',[[:blank:]]*')))
  imports <- trim.space(imports)
  imports <- filter.imports(imports)
  imports
}

make.dependency <- function(s)
{
  s <- gsub('\\\\)','',s)
  s <- unlist(strsplit(s,'\\\\('))
  s
}

depends <- function(s1,s2)
{
  imports <- make.imports(s1,s2)
  DEPENDS <- data.frame()
  BUILDLINK3.MK <- data.frame()
  if (length(imports) > 0)
    {
      for (i in 1:length(imports))
        {
          dependency <- make.dependency(imports[i])
          depends <- dependency[1]
          depends.pkg <- Sys.glob(paste('../../*/R-',depends,sep=''))
          if (length(depends.pkg) == 0) # a dependency cannot be found
            {
	      message('WARNING: creating the dependency',depends)
              if (${RECURSIVE})
                {
                  dependency.dir <- paste('../../wip/R-',depends,sep='')
                  dir.create(path=dependency.dir,recursive=TRUE)
                  error <- system(paste('(cd',dependency.dir,'&& ${R2PKG} ${ARGS}',depends,')'))
                  if (error != 0)
                    file.remove(dependency.dir)
                }
            }
          depends.pkg <- Sys.glob(paste('../../*/R-',depends,sep=''))
	  if (length(depends.pkg) == 0) # no dependency was created
	    message('WARNING: the dependency',depends,'does not exist')
          else if (length(depends.pkg) == 1) # a unique dependency found
            {
	      fields <- strsplit(depends.pkg,'/',fixed=TRUE)
	      depends.dir <- fields[[1]][3]
	      buildlink3.mk <- paste(depends.pkg,'/buildlink3.mk',sep='')
	      if (file.exists(buildlink3.mk))
                {
                  buildlink3.line <- paste('.include "',buildlink3.mk,'"',sep='')
                  BUILDLINK3.MK <- rbind(BUILDLINK3.MK,data.frame(key=depends.dir,value=buildlink3.line))
                }
	      else
	        {
                  depends.pkg.fullname <- system(paste('cd',depends.pkg,'&& bmake show-var VARNAME=PKGNAME'),intern=TRUE)
                  depends.pkg.name <- sub('^(.*)-([^-]*)$','\\\\1',depends.pkg.fullname)
                  depends.pkg.vers <- sub('^(.*)-([^-]*)$','\\\\2',depends.pkg.fullname)
                  if (length(dependency) == 2)
                    depends.vers <- dependency[2]
                  else
                    depends.vers <- paste('>=',depends.pkg.vers,sep='')
                  depends.line <- paste('DEPENDS+=\tR-',depends,depends.vers,':',depends.pkg,sep='')
                  depends.line <- paste(depends.line,'	# XXX - found ',depends.pkg.fullname,' (',depends.pkg,')',sep='')
                  DEPENDS <- rbind(DEPENDS,data.frame(key=depends.dir,value=depends.line))
                }
            }
          else			# more than 1 dependency found
            {
	      msg <- paste('WARNING: too many dependencies found for ',depends,':',sep='')
	      for (pkg in depends.pkg)
	        msg <- paste(msg,' ',pkg,sep='')
	      message(msg)
              depends.vers <- ifelse(length(dependency) == 2, dependency[2], '>=???')
              depends.vers <- trim.space(depends.vers)
              depends.line <- paste('DEPENDS+=\tR-',depends,depends.vers,':../../???/R-',depends,sep='')
 	      depends.line <- paste(depends.line,'	# XXX - found',sep='')
	      for (pkg in depends.pkg)
 	        depends.line <- paste(depends.line,' ',pkg,sep='')
              DEPENDS <- rbind(DEPENDS,data.frame(key='???',value=depends.line))
            }
          new.depends.pkg <- Sys.glob(paste('../../wip/R-',depends,sep=''))
          if (length(new.depends.pkg) > 0)
            system(paste('echo',depends,'${RPKG} >> ${DEPENDENCY_LIST}'))
        }
    }
  if (nrow(DEPENDS) > 0)
    {
      key <- as.vector(DEPENDS[,1])
      value <- as.vector(DEPENDS[,2])
      key <- order(key,value)
      DEPENDS <- as.list(value[key])
      if (length(DEPENDS) > 0)
        DEPENDS <- append(DEPENDS,'')
    }
  else
    DEPENDS = list()
  if (nrow(BUILDLINK3.MK) > 0)
    {
      key <- as.vector(BUILDLINK3.MK[,1])
      value <- as.vector(BUILDLINK3.MK[,2])
      key <- order(key,value)
      BUILDLINK3.MK <- as.list(value[key])
    }
  else
    BUILDLINK3.MK <- list()
  list(DEPENDS,BUILDLINK3.MK)
}

use.languages <- function(s1,s2)
{
  USE_LANGUAGES <- list()
  s <- paste(s1,s2)
  Rcpp <- grepl('Rcpp',s)
  if (Rcpp)
    USE_LANGUAGES <- append(USE_LANGUAGES,list('USE_LANGUAGES+=	c c++'))
  if (length(USE_LANGUAGES) > 0)
    USE_LANGUAGES <- append(USE_LANGUAGES,'')
  USE_LANGUAGES
}

copy.description <- function(connection)
{
  description <- readLines(connection)
  writeLines(description,con='DESCRIPTION')
}

error <- download.file(url='${RPKG_DESCRIPTION_URL}',destfile='DESCRIPTION',quiet=${QUIET_CURL},method='curl')
if (error)
  quit(status=error)

metadata <- read.dcf(file='DESCRIPTION', fields=c('Package','Version','Title','Description','License','Imports','Depends'))

CVS               <- '# \$NetBSD\$'
CATEGORIES        <- categories()
MASTER.SITES      <- 'MASTER_SITES=	\${MASTER_SITE_R_CRAN:=contrib/}'
MAINTAINER        <- maintainer('${MAINTAINER_EMAIL}')
HOMEPAGE          <- 'HOMEPAGE=	\${R_HOMEPAGE_BASE}/${RPKG}/'
COMMENT           <- comment(metadata[3])
LICENSE           <- license(metadata[5])
R_PKGNAME         <- package(metadata[1])
R_PKGVER          <- version(metadata[2])
USE_LANGUAGES     <- use.languages(metadata[6],metadata[7])
DEPENDENCIES      <- depends(metadata[6],metadata[7])
DEPENDS		  <- DEPENDENCIES[1]
BUILDLINK3.MK     <- DEPENDENCIES[2]
INCLUDE.R         <- '.include "../../math/R/Makefile.extension"'
INCLUDE.PKG       <- '.include "../../mk/bsd.pkg.mk"'

DESCR        <- description(metadata[4])

Makefile <- list()
Makefile <- append(Makefile,CVS)
Makefile <- append(Makefile,'')
Makefile <- append(Makefile,CATEGORIES)
Makefile <- append(Makefile,MASTER.SITES)
Makefile <- append(Makefile,'')
Makefile <- append(Makefile,MAINTAINER)
Makefile <- append(Makefile,HOMEPAGE)
Makefile <- append(Makefile,COMMENT)
Makefile <- append(Makefile,LICENSE)
Makefile <- append(Makefile,'')
Makefile <- append(Makefile,R_PKGNAME)
Makefile <- append(Makefile,R_PKGVER)
Makefile <- append(Makefile,'')
Makefile <- append(Makefile,USE_LANGUAGES)
Makefile <- append(Makefile,DEPENDS)
Makefile <- append(Makefile,INCLUDE.R)
Makefile <- append(Makefile,BUILDLINK3.MK)
Makefile <- append(Makefile,INCLUDE.PKG)
Makefile <- paste(unlist(Makefile),collapse='\n')

write(Makefile,'Makefile')
write(DESCR,'DESCR')
EOF
    eval ${R_CMD}
    retval=${?}
    if [ ${retval} -ne 0 ]; then
	echo "ERROR: making ${RPKG} package failed."
    fi
    return ${retval}
}

edit_Makefile ()
{
    if [ ${EDIT} -ne 0 -a -s Makefile ]; then
	${PKGEDITOR} Makefile
    fi
}

edit_DESCR ()
{
    if [ ${EDIT} -ne 0 -a -s DESCR ]; then
	${PKGEDITOR} DESCR
    fi
}

create_distinfo ()
{
    ${ECHO_FETCH} "==> Fetching R-${RPKG} ..."
    MAKE_CMD="${MAKE} makesum ${STDOUT_MAKESUM}"
    eval ${MAKE_CMD}
    return ${?}
}

extract ()
{
    ${ECHO_EXTRACT} "==> Extracting R-${RPKG} ..."
    MAKE_CMD="${MAKE} extract ${STDOUT_EXTRACT}"
    eval ${MAKE_CMD}
}

cleanup ()
{
    [ "X${DESCRIPTION}" != "X" ] || rm -f DESCRIPTION
    if [ -f DESCR.orig ] && cmp -s DESCR.orig DESCR; then
	mv DESCR.orig DESCR
    fi
    if [ -f Makefile.orig ] && cmp -s Makefile.orig Makefile; then
	mv Makefile.orig Makefile
    fi
    if [ -f distinfo.orig ] && cmp -s distinfo.orig distinfo; then
	mv distinfo.orig distinfo
    fi
    rm -f ${R_FILE}
    rm -f MAINTAINER
}

messages ()
{
    if [ ${QUIET} -eq 0 -a ${TOP_LEVEL} -ne 0 ]; then
	cat << EOF

Please do not forget the following:
- check DESCR and edit as necessary.
- check Makefile:
  o verify the COMMENT.
  o verify the LICENSE.
  o verify the DEPENDS, especially the categories.
EOF
	[ "X${DESCRIPTION}" != "X" ] && echo "- remove DESCRIPTION."
	if [ ${RECURSIVE} -ne 0 ]; then
	    cat << EOF

Recursive packages may have been created in ../../wip; please do the following:
- edit each Makefile as follows (in addition to following the notes above):
  o move recursively created packages to the appropriate category.
  o fix the category in Makefile.
  o fix the category of any dependencies.
  o remove any extraneous dependencies.
EOF
	    if [ -s ${DEPENDENCY_LIST} ]; then
		tsort ${DEPENDENCY_LIST} > depends
		echo "- It may be useful to test these packages in the following order:"
		awk 'BEGIN{printf(" ")} {printf(" R-%s",$0)}' depends && echo
		[ ${TOP_LEVEL} -eq 0 ] || rm -f ${DEPENDENCY_LIST}
	    fi
	fi
    fi
}

${ECHO_BANNER} "${BANNER_MSG} ..."
check_for_R
preserve_original_files
make_package
error=${?}
if [ ${error} -eq 0 ]; then
    edit_Makefile
    edit_DESCR
    create_distinfo
    error=${?}; [ ${error} -eq 0 ] || exit ${error}
    # extract
fi
cleanup
messages
${ECHO_DONE} "${BANNER_MSG}: done"
exit ${error}
