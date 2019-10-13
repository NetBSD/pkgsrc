#!/bin/sh
# $NetBSD: R2pkg.sh,v 1.7 2019/10/13 09:43:26 rillig Exp $
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

set -u

NAME="R2pkg"
VERS="@VERS@"

R2PKG=${0}

USAGE="${NAME} [-cDehqruVv] [-E editor] [-M maintainer] [package] -- create an R package for pkgsrc"

: ${CRAN_URL:=ftp://cran.r-project.org}
: ${PKGEDITOR:=${EDITOR:=vi}}
: ${TMPDIR:=/tmp}

# Substituted by pkgsrc at pre-configure time.
MAKE=@MAKE@
EDIT=1
LEVEL=0
MAINTAINER_EMAIL=pkgsrc-users@NetBSD.org
PID=$$
QUIET=0
RECURSIVE=0
UPDATE=0
VERBOSE=0

DESCRIPTION=no
DESCRIPTION_CONNECTION=connection

ARGS=""
while getopts cDehqruVvE:M:L:P: f
do
    case ${f} in
	# options without arguments
	c) UPDATE=0; ARGS="${ARGS} -c";;
	D) DESCRIPTION=yes; DESCRIPTION_CONNECTION="'DESCRIPTION'"; ARGS="${ARGS} -D";;
	e) EDIT=0; ARGS="${ARGS} -e";;
	h) echo "${USAGE}"; exit 0;;
	q) QUIET=1; ARGS="${ARGS} -q";;
	r) RECURSIVE=1; RECURSIVE_MESSAGE=1; ARGS="${ARGS} -r";;
	u) UPDATE=1; ARGS="${ARGS} -u";;
	V) echo "${NAME} v${VERS}"; exit 0;;
	v) VERBOSE=$((${VERBOSE}+1)); ARGS="${ARGS} -v";;
	# options taking arguments
	E) PKGEDITOR=${OPTARG}; ARGS="${ARGS} -E ${PKGEDITOR}";;
	M) MAINTAINER_EMAIL=${OPTARG}; ARGS="${ARGS} -M ${MAINTAINER_EMAIL}";;
	# options for recursion; only for internal use
	L) LEVEL=${OPTARG};;
	P) PID=${OPTARG};;
	# unknown options
        \?) echo "${USAGE}" 1>&2; exit 1;;
    esac
done
shift `expr ${OPTIND} - 1`

# Update ${ARGS} for recursive call
ARGS="${ARGS} -L $((${LEVEL}+1)) -P ${PID}"

if [ ${#} -eq 0 ]; then
    RPKG=$(basename $(pwd) | sed -e 's/^R-//')
elif [ ${#} -eq 1 ]; then
    RPKG=${1}
else
    echo "Error: multiple package names given." 1>&2
    echo "${USAGE}" 1>&2
    exit 1
fi

R_FILE=${TMPDIR}/R2pkg.$$.R

if [ ${UPDATE} -eq 1 -a -r Makefile ]; then
    BANNER_MSG="[ ${LEVEL} ] ===> Updating R package R-${RPKG} in $(pwd)"
else
    BANNER_MSG="[ ${LEVEL} ] ===> Creating R package R-${RPKG} in $(pwd)"
fi

PACKAGES_LIST=${TMPDIR}/R2pkg.packages.${PID}
DEPENDENCY_LIST=${TMPDIR}/R2pkg.depends.${PID}

if [ ${QUIET} -eq 1 ]; then
    STDOUT_MAKESUM=">/dev/null"
    STDOUT_EXTRACT=">/dev/null"
    QUIET_CURL="TRUE"
    ECHO_BANNER=":"
    ECHO_DONE=":"
    ECHO_FETCH=":"
    ECHO_EXTRACT=":"
    if [ ${LEVEL} -ne 0 ]; then
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
	echo "ERROR: math/R package is not installed." 1>&2
	exit 1
    fi
}

check_for_no_recursion ()
{
    touch ${PACKAGES_LIST}
    grep -E -q -e "${RPKG}" ${PACKAGES_LIST} \
	&& echo "ERROR: circular dependency" 1>&2
    echo "${RPKG}" >> ${PACKAGES_LIST}
}

preserve_original_content ()
{
    [ -f Makefile ] && grep -e "CATEGORIES=" Makefile > CATEGORIES
    [ -f Makefile ] && grep -e "COMMENT=" Makefile > COMMENT
    [ -f Makefile ] && grep -e "LICENSE=" Makefile > LICENSE
    [ -f Makefile ] && grep -e "MAINTAINER=" Makefile > MAINTAINER
    [ -f Makefile ] && grep -e "USE_LANGUAGES" Makefile > USE_LANGUAGES
    [ -f Makefile ] && grep -e "USE_TOOLS" Makefile > USE_TOOLS
    [ -f Makefile ] && grep -e "DEPENDS" Makefile > DEPENDS
    [ -f Makefile ] && grep -e "buildlink3.mk" Makefile > BUILDLINK3.MK

    [ -f DESCR ]    && mv DESCR DESCR.orig
    [ -f Makefile ] && mv Makefile Makefile.orig
    [ -f buildlink3.mk ] && mv buildlink3.mk buildlink3.mk.orig
    [ -f distinfo ] && mv distinfo distinfo.orig
}

make_package ()
{
    R_CMD="Rscript --no-save ${R_FILE}"
    cat << EOF > ${R_FILE}
R_version <- function()
{
  info <- R.Version()
  version <- paste0(info[['major']],'.',info[['minor']])
  version
}

set.locale <- function() { invisible(Sys.setlocale('LC_ALL','C')) }

trim.space <- function(s) gsub('[[:space:]]','',s)
trim.blank <- function(s) gsub('[[:blank:]]','',s)
one.space <- function(s) gsub('[[:blank:]]+',' ',s)
one.line <- function(s) gsub('\n',' ',s)
pkg.vers <- function(s) gsub('_','.',s)
field <- function(key,value) paste(key,'=\t',value,sep='')

# The list of "recommended packages which are to be included in all
# binary distributions of R." (R FAQ 5.1.2 2018-10-18)
#
base.packages.FAQ.5.1.2 <- c(
  'KernSmooth',
  'MASS',
  'Matrix',
  'boot',
  'class',
  'cluster',
  'codetools',
  'foreign',
  'lattice',
  'mgcv',
  'nlme',
  'nnet',
  'rpart',
  'spatial',
  'survival')

# Other R packages that appear in dependency lists but are included in
# the R package.
#
base.packages.other <- c(
  'grDevices',
  'graphics',
  'grid',
  'methods',
  'parallel',
  'splines',
  'stats',
  'tools',
  'utils')
base.packages <- c('R',base.packages.FAQ.5.1.2,base.packages.other)

licenses <- list()
licenses[['ACM']]                                    <- 'acm-license'
licenses[['ACM | file LICENSE']]                     <- 'acm-license	# OR file LICENSE'
licenses[['APACHE']]                                 <- 'apache-1.1 OR apache-2.0'
licenses[['Apache License 2.0']]                     <- 'apache-2.0'
licenses[['Apache License (== 2.0)']]                <- 'apache-2.0'
licenses[['Apache License (== 2.0) | file LICENSE']] <- 'apache-2.0	# OR file LICENSE'
licenses[['ARTISTIC']]                               <- 'artistic OR artistic-2.0'
licenses[['Artistic-2.0']]                           <- 'artistic-2.0'
licenses[['BSD']]                                    <- '2-clause-bsd OR modified-bsd OR original-bsd'
licenses[['BSD-2']]                                  <- '2-clause-bsd'
licenses[['BSD_2_clause + file LICENSE']]            <- '2-clause-bsd	# + file LICENSE'
licenses[['BSD 3 clause']]                           <- 'modified-bsd'
licenses[['BSD 3 clause + file LICENSE']]            <- 'modified-bsd	# + file LICENSE'
licenses[['BSD_3_clause + file LICENSE']]            <- 'modified-bsd	# + file LICENSE'
licenses[['BSL-1.0']]                                <- 'boost-license'
licenses[['CC0']]				     <- 'cc0-1.0-universal'
licenses[['GPL']]                                    <- 'gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3'
licenses[['GPL-1']]                                  <- 'gnu-gpl-v1'
licenses[['GPL-2']]                                  <- 'gnu-gpl-v2'
licenses[['GPL-2 | file LICENSE']]                   <- 'gnu-gpl-v2	# OR file LICENSE'
licenses[['GPL-3']]                                  <- 'gnu-gpl-v3'
licenses[['GPL-2 | GPL-3']]                          <- 'gnu-gpl-v2 OR gnu-gpl-v3'
licenses[['GPL (>= 2)']]                             <- 'gnu-gpl-v2 OR gnu-gpl-v3'
licenses[['GPL (>= 2.0)']]                           <- 'gnu-gpl-v2 OR gnu-gpl-v3'
licenses[['GPL (>= 2) | file LICENSE']]              <- 'gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE'
licenses[['GPL (>= 3)']]                             <- 'gnu-gpl-v3'
licenses[['LGPL']]                                   <- 'gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3'
licenses[['LGPL-2']]                                 <- 'gnu-lgpl-v2'
licenses[['LGPL-2.1']]                               <- 'gnu-lgpl-v2.1'
licenses[['LGPL-3']]                                 <- 'gnu-lgpl-v3'
licenses[['LGPL-3 + file LICENSE']]                  <- 'gnu-lgpl-v3	# + file LICENSE'
licenses[['LGPL-2 | LGPL-3']]                        <- 'gnu-lgpl-v2 OR gnu-lgpl-v3'
licenses[['LGPL (>= 2)']]                            <- 'gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3'
licenses[['LUCENT']]                                 <- 'lucent'
licenses[['Lucent Public License']]                  <- 'lucent'
licenses[['MIT']]                                    <- 'mit'
licenses[['MIT + file LICENSE']]                     <- 'mit	# + file LICENSE'
licenses[['MIT + file LICENSE | Unlimited']]         <- 'mit	# + file LICENSE OR unlimited'
licenses[['MPL-1.0']]                                <- 'mpl-1.0'
licenses[['MPL-1.1']]                                <- 'mpl-1.1'
licenses[['MPL-2.0']]                                <- 'mpl-2.0'
licenses[['MPL-2.0 | file LICENSE']]                 <- 'mpl-2.0	# OR file LICENSE'
licenses[['POSTGRESQL']]                             <- 'postgresql-license'

adjacent.duplicates <- function(x)
{
  a <- x[-length(x)]
  b <- x[-1]
  dups <- a == b
  dups <- c(FALSE,dups)
  dups
}

paste2 <- function(s1,s2)
{
  if (is.na(s1) && is.na(s2)) return ('')
  if (is.na(s1) && !is.na(s2)) return (s2)
  if (!is.na(s1) && is.na(s2)) return (s1)
  if (!is.na(s1) && !is.na(s2)) return (paste(s1,s2))
}

end.paragraph <- function(l,l1=l,l2=list())
{
  if (length(l1) > 0 || length(l2) > 0)
    l <- append(l,'')
  l
}

as.sorted.list <- function(df)
{
  l <- list()
  df <- df[!duplicated(df),]
  if (nrow(df) > 0)
    {
      key <- as.vector(df[,1])
      value <- as.vector(df[,2])
      key <- order(key,value)
      l <- as.list(value[key])
    }
  l
}

read.file.as.dataframe <- function(filename)
{
  # message('===> read.file.as.dataframe(',filename,')')
  contents <- as.list(readLines(filename))
  df <- data.frame()
  for (line in contents)
    {
      # str(line)
      df <- rbind(df,data.frame(line=line,stringsAsFactors=FALSE))
    }
  df
}

categorize.key_value <- function(df,line='line')
{
  re.skip_blank <- '[[:blank:]]*'
  re.blank <- '[[:blank:]]+'
  re.anything <- '.*'

  re.key <- '[^+=[:blank:]]+'
  re.operator <- '[+=]+'
  re.delimiter <- re.skip_blank
  re.value <- re.anything
  re.optional_TODO <- '(#[[:blank:]]*TODO[[:blank:]]*:[[:blank:]]*)*'

  re.match_key_value_line <- paste0('^',
    re.skip_blank,
    re.optional_TODO,
    re.key,
    re.skip_blank,
    re.operator,
    re.delimiter,
    re.value,
    '\$')

  re.match_key <- paste0('^',
    re.skip_blank,
    re.optional_TODO,
    '(',re.key,')',
    re.skip_blank,
    re.operator,
    re.delimiter,
    re.value,
    '\$')

  df\$key_value <- grepl(re.match_key_value_line,df[,line])
  df\$key <- sub(re.match_key,'\\\2',df[,line])
  df\$key[!df\$key_value] <- NA
  df
}

categorize.depends <- function(df,line='line')
{
  df\$depends <- df\$key_value & df\$key == 'DEPENDS'
  df\$category[df\$depends] <- unlist(sapply(strsplit(df[df\$depends,line],'/',fixed=TRUE),'[',3))
  df
}

categorize.buildlink <- function(df,line='line')
{
  df\$buildlink3.mk <- grepl('buildlink3.mk',df[,line])
  df\$category[df\$buildlink3.mk] <- unlist(sapply(strsplit(df[df\$buildlink3.mk,line],'/',fixed=TRUE),'[',3))
  df
}

fix.continued.lines <- function(df,line='line')
{
  if (nrow(df) > 1)
    {
      continued <- grepl('\\\\\\\\$',df[,line])
      continued_key_value <- df\$key_value & continued
      if (FALSE %in% df[continued,'key_value'])
        {
	  message('[ ${LEVEL} ] WARNING: unhandled continued line(s)')
	}
      for (i in 1:(length(continued_key_value)-1))
        {
	  next_line <- i + 1
	  if (continued_key_value[i])
	    {
	      df[i,line] <- sub('[[:blank:]]*\\\\\\\\$','',df[i,line])
	      df\$key_value[next_line] <- TRUE
	      df\$key[next_line] <- df\$key[i]
	      df[next_line,line] <- paste0(df\$key[next_line],'+=',df[next_line,line])
	    }
	}
    }
  df
}

read.Makefile.as.dataframe <- function()
{
  # message('===> read.Makefile.as.dataframe():')

  re.skip_blank <- '[[:blank:]]*'
  re.blank <- '[[:blank:]]+'
  re.anything <- '.*'

  re.key <- '[^+=[:blank:]]+'
  re.operator <- '[+=]+'
  re.delimiter <- re.skip_blank
  re.value <- re.anything
  re.optional_TODO <- '(#[[:blank:]]*TODO[[:blank:]]*:[[:blank:]]*)*'

  re.match_operator <- paste0('^',
    re.skip_blank,
    re.optional_TODO,
    re.key,
    re.skip_blank,
    '(',re.operator,')',
    re.delimiter,
    re.value,
    '\$')
  re.match_delimiter <- paste0('^',
    re.skip_blank,
    re.optional_TODO,
    re.key,
    re.skip_blank,
    re.operator,
    '(',re.delimiter,')',
    re.value,
    '\$')
  re.match_value <- paste0('^',
    re.skip_blank,
    re.optional_TODO,
    re.key,
    re.skip_blank,
    re.operator,
    re.delimiter,
    '(',re.value,')',
    '\$')
  re.match_optional_TODO <- paste0('^',
    re.skip_blank,
    '(',re.optional_TODO,')',
    re.key,
    re.skip_blank,
    re.operator,
    re.delimiter,
    re.value,
    '\$')

  df <- read.file.as.dataframe('Makefile.orig')

  df\$order <- 1:nrow(df)
  df\$category <- NA

  df <- categorize.key_value(df)
  df <- fix.continued.lines(df)
  df <- categorize.depends(df)
  df <- categorize.buildlink(df)

  df\$operator <- sub(re.match_operator,'\\\2',df\$line)
  df\$delimiter <- sub(re.match_delimiter,'\\\2',df\$line)
  df\$old_value <- sub(re.match_value,'\\\2',df\$line)
  df\$old_todo <- sub(re.match_optional_TODO,'\\\1',df\$line)

  df\$operator[!df\$key_value] <- NA
  df\$delimiter[!df\$key_value] <- NA
  df\$old_value[!df\$key_value] <- NA
  df\$old_todo[!df\$key_value] <- NA

  df
}

read.file.as.list <- function(filename)
{
  result <- list()
  info <- file.info(filename)
  size <- info[filename,'size']
  if (!is.na(size) && size > 0)
    {
       contents <- readLines(filename)
       result <- as.list(contents)
    }
  result
}

read.file.as.value <- function(filename)
{
  value <- ''
  l <- read.file.as.list(filename)
  if (length(l) == 1)
    {
      line <- l[[1]]
      fields <- strsplit(line,'[[:blank:]]+')
      value <- fields[[1]][2]
    }
  value
}

read.file.as.values <- function(filename)
{
  message('===> read.file.as.values(',filename,'):')
  values <- list()
  l <- read.file.as.list(filename)
  print(l)
  for (line in l)
    {
      # fields <- strsplit(line,'[[:blank:]]+')
      # value <- fields[[1]][2]
    }
  print(values)
  values
}

simplify.whitespace <- function(s) { gsub('[[:blank:]]+',' ',s) }
remove.punctuation <- function(s)
{
  punctuation <- '[,-]'
  gsub(punctuation,'',s)
}
remove.quotes <- function(s)
{
  quotes <- '[\'\`"]'
  gsub(quotes,'',s)
}
remove.articles <- function(s)
{
  pattern <- '^([[:blank:]]*)An* |([[:blank:]]+)[Aa]n*[[:blank:]]+'
  result <- gsub(pattern,'\\\1',s)
  result
}

case.insensitive.equals <- function(s1,s2)
{
  s1.lower <- tolower(simplify.whitespace(s1))
  s2.lower <- tolower(simplify.whitespace(s2))
  result <- s1.lower == s2.lower
  result
}

weakly.equals <- function(s1,s2)
{
  result <- case.insensitive.equals(remove.articles(remove.quotes(remove.punctuation(s1))),
                                    remove.articles(remove.quotes(remove.punctuation(s2))))
  result
}

new.field.if.different <- function(filename,s)
{
  field <- field(filename,one.line(s))
  field.list <- read.file.as.list(filename)
  if (length(field.list) == 1)
    {
      f <- field.list[[1]]
      if (case.insensitive.equals(f,field))
        field <- f
    }
  field
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

package <- function(s) one.line(s)
version <- function(s) one.line(s)
comment <- function(s) one.line(s)
use.tools <- function(s) read.file.as.list(s)

license <- function(s)
{
  license <- pkgsrc.license(s)
  old.license <- read.file.as.value('LICENSE')
  if (old.license != '' && old.license != license)
    license <- paste0(license,'	# [R2pkg] previously: ',old.license)
  license
}

maintainer <- function(email)
{
  MAINTAINER <- read.file.as.value('MAINTAINER')
  if (MAINTAINER == '')
    MAINTAINER <- email
  MAINTAINER
}

make.sed.command <- function(key,value)
{
  address <- paste0('/^[[:blank:]]*',key,'/')
  match <- paste0('(',key,'[[:blank:]]*=[[:blank:]]*).*$')
  replacement <- paste0('\\\1',value)
  command <- paste0(' -e "',address,'s/',match,'/',replacement,'/"')
  command
}

sed.categories <- function(categories) make.sed.command('CATEGORIES',categories)
sed.comment <- function(comment)
{
  old.comment <- read.file.as.value('COMMENT')
  if (weakly.equals(old.comment,comment))
    comment <- old.comment
  make.sed.command('COMMENT',comment)
}
sed.maintainer <- function(email)
{
  make.sed.command('MAINTAINER',maintainer(email))
}
sed.license <- function(license)
{
  make.sed.command('LICENSE',license)
}
sed.r_pkgver <- function(r_pkgver) make.sed.command('R_PKGVER',r_pkgver)

buildlink3.mk <- function(s1,s2)
{
  BUILDLINK3.MK <- data.frame()
  buildlink3.mk.list <- read.file.as.list('BUILDLINK3.MK')
  for (line in buildlink3.mk.list)
    {
      fields <- strsplit(line[[1]],'/',fixed=TRUE)
      key <- fields[[1]][3]
      value <- line
      BUILDLINK3.MK <- rbind(BUILDLINK3.MK,data.frame(key=key,value=value))
    }
  if (find.Rcpp(s1,s2))
    {
      buildlink3.line <- '.include "../../devel/R-Rcpp/buildlink3.mk"'
      key <- 'devel'
      value <- buildlink3.line
      BUILDLINK3.MK <- rbind(BUILDLINK3.MK,data.frame(key=key,value=value))
    }
  BUILDLINK3.MK
}

makefile.field <- function(key,value)
{
  # message('===> makefile.field(',key,',',value,'):')
  field <- paste0(key,'=	',value)
  # print(field)
  field
}

makefile.fields <- function(key,values)
{
  # message('===> makefile.fields():')
  fields <- list()
  for (l in values)
    {
      value <- unlist(l)
      # message('===> value=',value,' ',length(value),' ',value == '')
      # print(value)
      if (value != '')
        fields <- append(fields,makefile.field(key,list(value)))
      else
        fields <- append(fields,list(''))
      # print(fields)
    }
  # print(fields)
  fields
}

categories <- function() basename(dirname(getwd()))
description <- function(s) strwrap(s,width=71)

filter.imports <- function(s)
{
  for (pkg in base.packages)
    {
      re.pkg <- paste('^',pkg,sep='')
      s <- s[!grepl(re.pkg,s)]
    }
  s
}

find.Rcpp <- function(s1,s2)
{
  s <- paste(s1,s2)
  Rcpp <- grepl('Rcpp',s)
  Rcpp
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
  s <- gsub('-','.',s)
  s <- unlist(strsplit(s,'\\\\('))
  s
}

depends <- function(dependency) dependency[1]

depends.pkg <- function(dependency)
{
  # XXX message('===> ',depends(dependency))
  result <- Sys.glob(paste0('../../*/R-',depends(dependency)))
  result
}

new.depends.pkg <- function(dependency)
{
  result <- Sys.glob(paste0('../../wip/R-',depends(dependency)))
  result
}

depends.pkg.fullname <- function(dependency,index=1)
{
  result <- system(paste('cd',depends.pkg(dependency)[index],'&& bmake show-var VARNAME=PKGNAME'),intern=TRUE)
  result
}

depends.pkg.name <- function(dependency,index=1)
{
  result <- sub('^(.*)-([^-]*)$','\\\\1',depends.pkg.fullname(dependency,index))
  result
}

depends.pkg.vers <- function(dependency,index=1)
{
  result <- sub('^(.*)-([^-]*)$','\\\\2',depends.pkg.fullname(dependency,index))
  result
}

depends.vers <- function(dependency,index=1)
{
  if (length(dependency) == 2)
    result <- dependency[2]
  else
    result <- paste0('>=',depends.pkg.vers(dependency,index))
  result <- trim.space(result)
  result
}

depends.vers.2 <- function(dependency)
{
  result <- ifelse(length(dependency) == 2, dependency[2], '>=???')
  result <- trim.space(result)
  result
}

depends.dir <- function(dependency,index=1)
{
  fields <- strsplit(depends.pkg(dependency)[index],'/',fixed=TRUE)
  result <- fields[[1]][3]
  result
}

depends.line <- function(dependency,index=1)
{
  result <- paste0('DEPENDS+=\tR-',depends(dependency),depends.vers(dependency,index),':',depends.pkg(dependency)[index])
  result
}

depends.line.2 <- function(dependency)
{
  result <- paste0('DEPENDS+=\tR-',depends,depends.vers.2(dependency),':../../???/R-',depends)
  result <- paste0(result,'	# XXX - found')
  for (pkg in depends.pkg(dependency))
    result <- paste(result,pkg)
  result
}

buildlink3.file <- function(dependency,index=1)
{
  result <- paste0(depends.pkg(dependency)[index],'/buildlink3.mk')
  result
}

buildlink3.line <- function(dependency,index=1)
{
  result <- paste0('.include "',buildlink3.file(dependency,index),'"')
  result
}

dependency.dir <- function(dependency)
{
  result <- paste0('../../wip/R-',depends(dependency))
  result
}

message.wip.dependency <- function(dependency,index=1)
{
  dir <- depends.dir(dependency,index)
  dir.in.wip <- grepl('wip',dir)
  wd.in.wip <- grepl('/wip/',getwd())
  if (dir.in.wip && !wd.in.wip)
    message('[ ${LEVEL} ] WARNING: R-${RPKG} should not depend on a wip package: ',depends.pkg(dependency)[index])
}

message.too.many.dependencies <- function(dependency)
{
  msg <- paste0('[ ${LEVEL} ] WARNING: too many dependencies found for ',depends(dependency),':')
  for (pkg in depends.pkg(dependency))
    msg <- paste(msg,pkg)
  msg
}

update.dependency <- function(dependency,index=1)
{
  message('[ ${LEVEL} ] WARNING: updating dependency for ',depends(dependency),': ',depends.pkg(dependency)[index])
  grep <- paste0('grep -E -q -e "',depends(dependency),'" ${PACKAGES_LIST}')
  command <- paste0(grep,' || (cd ',depends.pkg(dependency)[index],' && ${R2PKG} ${ARGS} ',depends(dependency),')')
  error <- system(command)
  if (error != 0)
    message('[ ${LEVEL} ] WARNING: error updating dependency for ',depends(dependency))
}

make.depends <- function(s1,s2)
{
  imports <- make.imports(s1,s2)
  # XXX  message('===> imports:')
  # XXX print(imports)
  DEPENDS <- data.frame()
  BUILDLINK3.MK <- buildlink3.mk(s1,s2)
  if (length(imports) > 0)
    {
      for (i in 1:length(imports))
        {
          dependency <- make.dependency(imports[i])
	  # XXX message('[ ',${LEVEL},' ] ===> ',i,' / ',length(imports),': ',depends(dependency))
          if (length(depends.pkg(dependency)) == 0) # a dependency cannot be found
            {
	      message('[ ${LEVEL} ] 0 dependencies match ',dependency)
              if (${RECURSIVE})
	        {
                  dir.create(path=dependency.dir(dependency),recursive=TRUE)
 		  update.dependency(dependency)
 		}
              else
                message('[ ${LEVEL} ] WARNING: dependency needed for ',depends(dependency))
            }
	  else if (length(depends.pkg(dependency)) == 1) # a unique dependency found
            {
	      message('[ ${LEVEL} ] 1 dependency matches ',dependency,': ',depends.pkg(dependency))
	      message.wip.dependency(dependency)
              if (${RECURSIVE} && ${UPDATE})
	        update.dependency(dependency)
	      if (file.exists(buildlink3.file(dependency)))
                BUILDLINK3.MK <- rbind(BUILDLINK3.MK,data.frame(key=depends.dir(dependency),value=buildlink3.line(dependency)))
	      else
                DEPENDS <- rbind(DEPENDS,data.frame(key=depends.dir(dependency),value=depends.line(dependency)))
            }
	  else if (length(depends.pkg(dependency)) == 2) # two dependencies found
	    {
	      d <- depends.pkg(dependency)
	      index <- grep('/wip/',d,invert=TRUE)
	      message('[ ${LEVEL} ] 2 dependencies match ',dependency,':',paste(' ',depends.pkg(dependency)))
	      # message('===> depends(dependency): ',depends(dependency))
	      # message('===> depends.pkg(dependency):',paste(' ',d))
	      # message('===> index: ',index)
	      # message('===> buildlinke.line(): ',buildlink3.line(dependency,index))
	      if (length(index) == 1) # a unique, non-wip, dependency found
	        {
		  message('[ ${LEVEL} ] choosing unique non-wip dependency for ',dependency,': ',depends.pkg(dependency)[index])
		  if (${RECURSIVE} && ${UPDATE})
	            update.dependency(dependency,index)
	      	  if (file.exists(buildlink3.file(dependency,index)))
                    BUILDLINK3.MK <- rbind(BUILDLINK3.MK,data.frame(key=depends.dir(dependency,index),value=buildlink3.line(dependency,index)))
		  else
                    DEPENDS <- rbind(DEPENDS,data.frame(key=depends.dir(dependency,index),value=depends.line(dependency,index)))
		}
	      else
	        {
		  message('[ ${LEVEL} ] no unique non-wip dependency matches')
		  message(message.too.many.dependencies(dependency))
              	  DEPENDS <- rbind(DEPENDS,data.frame(key='???',value=depends.line.2(dependency)))
		}
	    }
          else			# more than 2 dependencies found
            {
	      message('[ ${LEVEL} ] ',length(depends.pkg(dependency)),' dependencies match ',dependency,':',paste(' ',depends.pkg(dependency)))
 	      message(message.too.many.dependencies(dependency))
              DEPENDS <- rbind(DEPENDS,data.frame(key='???',value=depends.line.2(dependency)))
            }
          if (length(new.depends.pkg(dependency)) > 0)
            system(paste('echo',depends(dependency),'${RPKG} >> ${DEPENDENCY_LIST}'))
        }
    }
  DEPENDS <- as.sorted.list(DEPENDS)
  DEPENDS <- end.paragraph(DEPENDS)
  BUILDLINK3.MK <- as.sorted.list(BUILDLINK3.MK)
  result <- list(DEPENDS,BUILDLINK3.MK)
  result
}

use.languages <- function(s1,s2)
{
#  message('===> use.languages(',s1,',',s2,'):')
#  USE_LANGUAGES <- read.file.as.values('USE_LANGUAGES')
#  if (length(USE_LANGUAGES) == 0)
#    {
#      if (find.Rcpp(s1,s2))
#        USE_LANGUAGES <- append(USE_LANGUAGES,list('USE_LANGUAGES+=	c c++'))
#    }
  USE_LANGUAGES <- list()
  if (find.Rcpp(s1,s2))
    USE_LANGUAGES <- append(USE_LANGUAGES,list('c c++'))
  if (length(USE_LANGUAGES) == 0)
    USE_LANGUAGES <- '# none'
  USE_LANGUAGES <- end.paragraph(USE_LANGUAGES)
  USE_LANGUAGES
}

copy.description <- function(connection)
{
  description <- readLines(connection)
  writeLines(description,con='DESCRIPTION')
}

write.Makefile <- function(metadata)
{
  RCSID             <- '# \$NetBSD\$'
  CATEGORIES        <- makefile.field('CATEGORIES',categories())
  MAINTAINER        <- makefile.field('MAINTAINER',maintainer('${MAINTAINER_EMAIL}'))
  COMMENT           <- makefile.field('COMMENT',comment(metadata[3]))
  LICENSE           <- makefile.field('LICENSE',license(metadata[5]))
  R_PKGNAME         <- makefile.field('R_PKGNAME',package(metadata[1]))
  R_PKGVER          <- makefile.field('R_PKGVER',version(metadata[2]))
  USE_LANGUAGES     <- makefile.fields('USE_LANGUAGES',use.languages(metadata[6],metadata[7]))
  DEPENDENCIES      <- make.depends(metadata[6],metadata[7])
  DEPENDS	    <- DEPENDENCIES[1]
  BUILDLINK3.MK     <- DEPENDENCIES[2]
  INCLUDE.R         <- '.include "../../math/R/Makefile.extension"'
  INCLUDE.PKG       <- '.include "../../mk/bsd.pkg.mk"'

  Makefile <- list()
  Makefile <- append(Makefile,RCSID)
  Makefile <- append(Makefile,'')
  Makefile <- append(Makefile,R_PKGNAME)
  Makefile <- append(Makefile,R_PKGVER)
  Makefile <- append(Makefile,CATEGORIES)
  Makefile <- append(Makefile,'')
  Makefile <- append(Makefile,MAINTAINER)
  Makefile <- append(Makefile,COMMENT)
  Makefile <- append(Makefile,LICENSE)
  Makefile <- append(Makefile,'')
  Makefile <- append(Makefile,DEPENDS)
  Makefile <- append(Makefile,USE_LANGUAGES)
  Makefile <- append(Makefile,INCLUDE.R)
  Makefile <- append(Makefile,BUILDLINK3.MK)
  Makefile <- append(Makefile,INCLUDE.PKG)
  Makefile <- paste(unlist(Makefile),collapse='\n')

  write(Makefile,'Makefile')
}

construct.line <- function(df,key,value)
{
  key <- df[df\$key==key,'key']
  operator <- df[df\$key==key,'operator']
  delimiter <- df[df\$key==key,'delimiter']
  value <- df[df\$key==key,value]
  df\$new_line[df\$key==key] <- paste0(key,operator,delimiter,value)
  df
}

element <- function(df,key,value,quiet=FALSE)
{
  key.index <- match(key,df\$key,0)
  if (key.index != 0 && df\$key_value[key.index])
    result <- df[key.index,value]
  else
    {
      result <- '???'
      if (!quiet)
        {
          if (key.index == 0)
            message('[ ${LEVEL} ] WARNING: ',key,' not found')
          else
            message('[ ${LEVEL} ] WARNING: ',key,' is not a key-value field')
	}
    }
  result
}

make.categories <- function(df)
{
  # message('===> make.categories():')
  directory <- basename(dirname(getwd()))
  categories <- unlist(element(df,'CATEGORIES','old_value'))
  categories <- unlist(strsplit(categories,'[[:blank:]]+'))
  categories <- c(directory,categories)
  categories <- categories[ categories != 'R' ]
  if (directory != 'wip')
    categories <- categories[ categories != 'wip' ]
  categories <- categories[!duplicated(categories)]
  categories <- paste(categories,collapse=' ')
  categories
}

make.maintainer <- function(df)
{
  old.maintainer <- element(df,'MAINTAINER','old_value')
  new.maintainer <- element(df,'MAINTAINER','new_value')
  maintainer <- ifelse(old.maintainer == '',new.maintainer,old.maintainer)
  maintainer
}

make.comment <- function(df)
{
  old.comment <- element(df,'COMMENT','old_value')
  new.comment <- element(df,'COMMENT','new_value')
  comment <- old.comment
  if (!weakly.equals(old.comment,new.comment))
    comment <- paste0(comment,'	# [R2pkg] updated to: ',new.comment)
  comment
}

make.new_license <- function(df,license)
{
  new_license <- licenses[[license]]
  if (is.null(new_license))
      new_license <- license
  df\$new_value[df\$key == 'LICENSE'] <- new_license
  df
}

license.marked.todo <- function(todo) { todo != '' }
license.in.pkgsrc <- function(license) { license %in% sapply(licenses,'[',1) }

make.license <- function(df)
{
  # message('===> make.license():')
  old_license <- element(df,'LICENSE','old_value')
  old_todo <- element(df,'LICENSE','old_todo')
  new_license <- element(df,'LICENSE','new_value')

  if (license.in.pkgsrc(old_license) && license.in.pkgsrc(new_license))
    {
      if (case.insensitive.equals(old_license,new_license))
        {
          license <- old_license
          todo <- old_todo
        }
      else
        {
          license <- paste0(new_license,'	# [R2pkg] previously: ',old_license)
          todo <- old_todo
        }
    }
  else if (license.in.pkgsrc(old_license) && !license.in.pkgsrc(new_license))
    {
      license <- paste0(old_license,'	# [R2pkg] updated to: ',new_license)
      todo <- '# TODO: '
    }
  else if (!license.in.pkgsrc(old_license) && license.in.pkgsrc(new_license))
    {
      license <- paste0(new_license,'	# [R2pkg] previously: ',old_license)
      todo <- ''
    }
  else if (!license.in.pkgsrc(old_license) && !license.in.pkgsrc(new_license))
    {
      license <- paste0(new_license,'	# [R2pkg] previously: ',old_license)
      todo <- '# TODO: '
    }

  df\$value[df\$key == 'LICENSE'] <- license
  df\$todo[df\$key == 'LICENSE'] <- todo

  df
}

make.r_pkgver <- function(df) element(df,'R_PKGVER','new_value')

find.order <- function(df,key,field)
{
  x <- df[,key]
  value <- match(TRUE,x)
  if (!is.na(value))
    value <- df[value,field]
  value
}

write.makefile <- function(lines) write(lines,'Makefile')

update.Makefile.with.metadata <- function(df,metadata)
{
  # message('===> update.Makefile.with.metadata():')

  df\$new_value <- NA

  df <- make.new_license(df,metadata[5])

  df\$new_value[df\$key == 'CATEGORIES'] <- categories()
  df\$new_value[df\$key == 'MAINTAINER'] <- '${MAINTAINER_EMAIL}'
  df\$new_value[df\$key == 'COMMENT'] <- one.line(metadata[3])
  df\$new_value[df\$key == 'R_PKGVER'] <- version(metadata[2])

  # str(df)
  # print(df)
  df
}

update.Makefile.with.new.values <- function(df)
{
  # message('===> update.Makefile.with.new.values():')
  df\$value <- NA
  df\$todo <- ''
  df <- make.license(df)
  df\$value[df\$key == 'CATEGORIES'] <- make.categories(df)
  df\$value[df\$key == 'MAINTAINER'] <- make.maintainer(df)
  df\$value[df\$key == 'COMMENT'] <- make.comment(df)
  df\$value[df\$key == 'R_PKGVER'] <- make.r_pkgver(df)

  # str(df)
  # print(df)
  df
}

update.Makefile.with.new.line <- function(df)
{
  # message('===> update.Makefile.with.new.line():')
  df\$new_line <- NA

  construct_key_value <- df\$key_value & !is.na(df\$value)
  df\$new_line[construct_key_value] <-
    paste0(df\$todo[construct_key_value],
           df\$key[construct_key_value],
           df\$operator[construct_key_value],
           df\$delimiter[construct_key_value],
           df\$value[construct_key_value])

  copy_line <- !df\$key_value | !construct_key_value
  df\$new_line[copy_line] <- df\$line[copy_line]

  # str(df)
  # print(df)
  df
}

annotate.distname.in.Makefile <- function(df)
{
  match <- grepl('^[[:blank:]]*DISTNAME',df\$new_line)
  line <- df\$new_line[match]
  value <- sub('^[[:blank:]]*DISTNAME[[:blank:]]*=[[:blank:]]*','',line)
  pkgname <- sub('_.+$','',value)
  pkgver <- sub('^.+_','',value)
  PKGNAME <- paste0('R_PKGNAME=',pkgname)
  PKGVER <- paste0('R_PKGVER=',pkgver)
  comment <- paste0('	# [R2pkg] replace this line with ',PKGNAME,' and ',PKGVER,' as first stanza')
  df\$new_line[match] <- paste0(line,comment)
  df
}

annotate.Makefile <- function(df)
{
  df <- annotate.distname.in.Makefile(df)
  df
}

remove.master.sites.from.Makefile <- function(df)
{
  match <- grepl('^[[:blank:]]*MASTER_SITES',df\$new_line)
  df <- df[!match,]
  df
}

remove.homepage.from.Makefile <- function(df)
{
  match <- grepl('^[[:blank:]]*HOMEPAGE',df\$new_line)
  df <- df[!match,]
  df
}

remove.buildlink.abi.depends.from.Makefile <- function(df)
{
  match <- grepl('^[[:blank:]]*BUILDLINK_ABI_DEPENDS',df\$new_line)
  df <- df[!match,]
  df
}

remove.buildlink.api.depends.from.Makefile <- function(df)
{
  match <- grepl('^[[:blank:]]*BUILDLINK_API_DEPENDS',df\$new_line)
  df <- df[!match,]
  df
}

remove.lines.from.Makefile <- function(df)
{
  df <- remove.master.sites.from.Makefile(df)
  df <- remove.homepage.from.Makefile(df)
  df <- remove.buildlink.abi.depends.from.Makefile(df)
  df <- remove.buildlink.api.depends.from.Makefile(df)
  df
}

reassign.order <- function(df)
{
  # message('===> reassign.order():')
  # str(df)
  # print(df)

  r_pkgname.order <- element(df,'R_PKGNAME','order')
  categories.order <- element(df,'CATEGORIES','order')
  if (r_pkgname.order > categories.order)
    {
      r_pkgname.index <- df\$key == 'R_PKGNAME'
      r_pkgname.index[ is.na(r_pkgname.index) ] <- FALSE
      r_pkgver.index <- df\$key == 'R_PKGVER'
      r_pkgver.index[ is.na(r_pkgver.index) ] <- FALSE
      df[r_pkgname.index,'order'] <- categories.order - 0.2
      df[r_pkgver.index,'order'] <- categories.order - 0.1
    }
  df
}

conflicts <- function(pkg)
{
  conflict <- paste0('R>=',R_version())
  conflicts <- list()
  if (pkg %in% base.packages)
    {
      conflicts <- append(conflicts,makefile.field('CONFLICTS',conflict))
      conflicts <- end.paragraph(conflicts)
    }
  conflicts
}

conflicts.order <- function(df)
{
  order <- element(df,'COMMENT','order')
  order
}

make.df.conflicts <- function(df,metadata)
{
  df.conflicts <- data.frame()
  conflicts.exist <- element(df,'CONFLICTS','old_value',quiet=TRUE) != '???'
  if (!conflicts.exist)
    {
      c <- conflicts(metadata[1])
      order <- conflicts.order(df)
      order <- order + 2.5
      i <- 0
      for (conflict in c)
        {
          i <- i + 1
          category <- as.character(i)
          depends <- FALSE
          buildlink3.mk <- FALSE
          x <- data.frame(new_line=conflict,order=order,category=category,depends=depends,buildlink3.mk=buildlink3.mk)
          df.conflicts <- rbind(df.conflicts,x)
        }
    }
  df.conflicts
}

make.df.depends <- function(df,DEPENDS)
{
  # message('===> make.df.depends():')
  # str(df)
  # print(df)
  df.depends <- data.frame()
  if (TRUE %in% df\$depends)
    df.depends <- data.frame(new_line=df[df\$depends,'line'],stringsAsFactors=FALSE)
  for (line in DEPENDS)
    df.depends <- rbind(df.depends,data.frame(new_line=line,stringsAsFactors=FALSE))
  if (nrow(df.depends) > 0)
    {
      df.depends\$category <- NA
      df.depends\$buildlink3.mk <- FALSE
      df.depends <- categorize.key_value(df.depends,'new_line')
      df.depends <- categorize.depends(df.depends,'new_line')
      df.depends\$key_value <- NULL
      df.depends\$key <- NULL
      df.depends <- df.depends[!duplicated(df.depends),]
      df.depends\$order <- find.order(df,'depends','order')
    }
  # message('===> df.depends:')
  # str(df.depends)
  # print(df.depends)
  df.depends
}

make.df.buildlink3 <- function(df,BUILDLINK3.MK)
{
  # message('===> make.df.buildlink3():')
  df.buildlink3.mk <- data.frame()
  if (TRUE %in% df\$buildlink3.mk)
    df.buildlink3.mk <- data.frame(new_line=df[df\$buildlink3.mk,'line'],stringsAsFactors=FALSE)
  for (line in BUILDLINK3.MK)
    df.buildlink3.mk <- rbind(df.buildlink3.mk,data.frame(new_line=line,stringsAsFactors=FALSE))
  if (nrow(df.buildlink3.mk) > 0)
    {
      df.buildlink3.mk\$category <- NA
      df.buildlink3.mk\$depends <- FALSE
      df.buildlink3.mk <- categorize.buildlink(df.buildlink3.mk,'new_line')
      df.buildlink3.mk <- df.buildlink3.mk[!duplicated(df.buildlink3.mk),]
      df.buildlink3.mk\$order <- find.order(df,'buildlink3.mk','order')
    }
  # str(df.buildlink3.mk)
  # print(df.buildlink3.mk)
  df.buildlink3.mk
}

make.df.makefile <- function(df,df.conflicts,df.depends,df.buildlink3.mk)
{
  # message('===> make.df.makefile():')
  # message('===> df:')
  # str(df)
  # print(df)
  fields <- c('new_line','order','category','depends','buildlink3.mk')
  df.makefile <- df[!df\$depends & !df\$buildlink3.mk,fields]
  df.makefile <- rbind(df.makefile,df.conflicts,df.depends,df.buildlink3.mk)
  df.makefile <- df.makefile[order(df.makefile\$order,df.makefile\$category,df.makefile\$new_line),]
  df.makefile <- df.makefile[!adjacent.duplicates(df.makefile\$new_line),]
  df.makefile
}

update.Makefile <- function(metadata)
{
  DEPENDENCIES  <- make.depends(metadata[6],metadata[7])
  DEPENDS       <- DEPENDENCIES[[1]]
  BUILDLINK3.MK <- DEPENDENCIES[[2]]
  # message('===> DEPENDS:')
  # str(DEPENDS)
  # print(DEPENDS)
  # message('===> BUILDLINK3.MK:')
  # str(BUILDLINK3.MK)
  # print(BUILDLINK3.MK)

  # message('===> df:')
  df <- read.Makefile.as.dataframe()
  df <- update.Makefile.with.metadata(df,metadata)
  df <- update.Makefile.with.new.values(df)
  df <- update.Makefile.with.new.line(df)
  df <- annotate.Makefile(df)
  df <- remove.lines.from.Makefile(df)
  df <- reassign.order(df)

  df.conflicts <- make.df.conflicts(df,metadata)
  df.depends <- make.df.depends(df,DEPENDS)
  df.buildlink3 <- make.df.buildlink3(df,BUILDLINK3.MK)
  df.makefile <- make.df.makefile(df,df.conflicts,df.depends,df.buildlink3)

  write.makefile(df.makefile[,'new_line'])
}

create.Makefile <- function(metadata)
{
  if (${UPDATE} == 1 && file.exists('Makefile.orig'))
    update.Makefile(metadata)
  else
    write.Makefile(metadata)
}

create.DESCR <- function(metadata)
{
  DESCR <- description(metadata[4])
  write(DESCR,'DESCR')
}

set.locale()

error <- download.file(url='${RPKG_DESCRIPTION_URL}',destfile='DESCRIPTION',quiet=${QUIET_CURL},method='curl')
if (error)
  {
    message('ERROR: Downloading the DESCRIPTION file for ${RPKG} failed;')
    message('       perhaps the package no longer exists?')
    quit(save='no',status=error)
  }

metadata <- read.dcf(file='DESCRIPTION', fields=c('Package','Version','Title','Description','License','Imports','Depends'))

create.Makefile(metadata)
create.DESCR(metadata)
EOF
    eval ${R_CMD}
    retval=${?}
    if [ ${retval} -ne 0 ]; then
	echo "ERROR: making ${RPKG} package failed." 1>&2
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
    error=${?}
    if [ ${error} -eq 0 ]; then
	MAKE_CMD="${MAKE} makepatchsum ${STDOUT_MAKESUM}"
	eval ${MAKE_CMD}
	error=${?}
    fi
    return ${error}
}

create_buildlink3_mk ()
{
    if [ -f buildlink3.mk.orig ]; then
	PKGVERSION=$(${MAKE} show-var VARNAME=PKGVERSION)
	sed -E -e "/BUILDLINK_API_DEPENDS\./s/[[:digit:].]+$/${PKGVERSION}/" \
	    buildlink3.mk.orig > buildlink3.mk
    fi
}

extract ()
{
    ${ECHO_EXTRACT} "[ ${LEVEL} ] Extracting R-${RPKG} ..."
    MAKE_CMD="env SKIP_DEPENDS=yes ${MAKE} clean extract ${STDOUT_EXTRACT}"
    eval ${MAKE_CMD}
}

check_license ()
{
    rm -f LICENSE
    # echo '===> LICENSE files:'
    if [ -f work/*/LICENSE ]; then
	grep -v "^YEAR: " work/*/LICENSE \
	    | grep -v "^COPYRIGHT HOLDER: " \
	    | grep -v "^ORGANIZATION: " \
	    > LICENSE
	if [ -s LICENSE ]; then
	    # ninka -d LICENSE
	    cp work/*/LICENSE .
	    /bin/echo -n "[ ${LEVEL} ] Current license: "
	    grep LICENSE Makefile
	    echo "[ ${LEVEL} ] Please check it against the following:"
	    cat LICENSE
	else
	    rm LICENSE
	    sed -E -e 's/[[:blank:]]+#[[:blank:]]+\+ file LICENSE[[:blank:]]+.*$//' Makefile > Makefile.$$ \
		&& mv Makefile.$$ Makefile
	    grep -q "file LICENSE" Makefile && echo "[ ${LEVEL} ] 'file LICENSE' in Makefile but no relevant license information"
	fi
    fi
}

check_copying ()
{
    if [ -f work/*/COPYING ]; then
	cp work/*/COPYING .
    fi
    if [ -f work/*/COPYING.lib ]; then
	cp work/*/COPYING.lib .
    fi
}

cleanup_DESCR ()
{
    if [ -f DESCR -a -f DESCR.orig ]; then
	if diff --ignore-case --ignore-all-space --ignore-blank-lines DESCR.orig DESCR > /dev/null; then
	    mv DESCR.orig DESCR
	else
	    mv DESCR DESCR.new
	    mv DESCR.orig DESCR
	fi
    elif [ -f DESCR.orig ]; then
	mv DESCR.orig DESCR
    fi
}

cleanup_Makefile ()
{
    if [ -f Makefile -a -f Makefile.orig ]; then
	diff --ignore-case --ignore-all-space --ignore-blank-lines Makefile.orig Makefile > /dev/null \
	    && mv Makefile.orig Makefile
    elif [ -f Makefile.orig ]; then
	mv Makefile.orig Makefile
    else
	echo "[ ${LEVEL} ] $(pwd): neither Makefile nor Makefile.orig"
    fi
}

cleanup_buildlink3 ()
{
    if [ buildlink3.mk -a -f buildlink3.mk.orig ]; then
	diff --ignore-case --ignore-all-space --ignore-blank-lines buildlink3.mk.orig buildlink3.mk > /dev/null \
	    && mv buildlink3.mk.orig buildlink3.mk
    elif [ -f buildlink3.mk.orig ]; then
	mv buildlink3.mk.orig buildlink3.mk
    fi
}

cleanup_distinfo ()
{
    if [ -f distinfo -a -f distinfo.orig ]; then
	tail +2 distinfo.orig > ${TMPDIR}/distinfo.orig.${PID}
	tail +2 distinfo > ${TMPDIR}/distinfo.${PID}
	cmp -s ${TMPDIR}/distinfo.orig.${PID} ${TMPDIR}/distinfo.${PID} \
	    && mv distinfo.orig distinfo
	rm -f ${TMPDIR}/distinfo.orig.${PID} ${TMPDIR}/distinfo.${PID}
    elif [ -f distinfo.orig ]; then
	mv distinfo.orig distinfo
    fi
}

cleanup_misc_files ()
{
    [ "${DESCRIPTION}" = "yes" ] || rm -f DESCRIPTION
    rm -f ${R_FILE}
    rm -f CATEGORIES
    rm -f COMMENT
    rm -f MAINTAINER
    rm -f USE_LANGUAGES
    rm -f USE_TOOLS
    rm -f DEPENDS
    rm -f BUILDLINK3.MK
    [ ${LEVEL} -eq 0 ] && rm -f ${PACKAGES_LIST}
    [ ${LEVEL} -eq 0 ] && rm -f ${DEPENDENCY_LIST}
}

cleanup ()
{
    cleanup_DESCR
    cleanup_Makefile
    cleanup_buildlink3
    cleanup_distinfo
    cleanup_misc_files
}

messages ()
{
    if [ ${QUIET} -eq 0 -a ${LEVEL} -eq 0 ]; then
	cat << EOF

Please do not forget the following:
- check DESCR and edit as necessary.
- check Makefile:
  o verify the COMMENT.
  o verify the LICENSE.
  o verify the DEPENDS, especially the categories.
EOF
	[ -f buildlink3.mk ] && echo "- check buildlink3.mk"

	[ "${DESCRIPTION}" = "yes" ] && echo "- remove DESCRIPTION."
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
	    fi
	fi
    fi
}

${ECHO_BANNER} "${BANNER_MSG} ..."
check_for_R
check_for_no_recursion
preserve_original_content
make_package
error=${?}
if [ ${error} -eq 0 ]; then
    edit_Makefile
    error=${?}; [ ${error} -eq 0 ] || exit ${error}
    edit_DESCR
    error=${?}; [ ${error} -eq 0 ] || exit ${error}
    create_distinfo
    create_buildlink3_mk
    extract
    check_license
    check_copying
fi
messages
cleanup
if [ ${error} -eq 0 ]; then
    ${ECHO_DONE} "${BANNER_MSG}: completed successfully"
else
    ${ECHO_DONE} "${BANNER_MSG}: FAILED"
fi
exit ${error}
