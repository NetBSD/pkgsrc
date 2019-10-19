# $NetBSD: R2pkg.R,v 1.21 2019/10/19 17:30:10 rillig Exp $
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

arg.level                <- as.integer(Sys.getenv('LEVEL'))
arg.rpkg                 <- Sys.getenv('RPKG')
arg.packages_list        <- Sys.getenv('PACKAGES_LIST')
arg.r2pkg                <- Sys.getenv('R2PKG')
arg.args                 <- Sys.getenv('ARGS')
arg.recursive            <- as.logical(Sys.getenv('RECURSIVE'))
arg.update               <- as.logical(Sys.getenv('UPDATE'))
arg.dependency_list      <- Sys.getenv('DEPENDENCY_LIST')
arg.maintainer_email     <- Sys.getenv('MAINTAINER_EMAIL')
arg.rpkg_description_url <- Sys.getenv('RPKG_DESCRIPTION_URL')
arg.quiet_curl           <- as.logical(Sys.getenv('QUIET_CURL'))

mkcvsid <- paste0('# $', 'NetBSD$')

level.message <- function(...)
  message('[ ', arg.level, ' ] ', ...)

level.warning <- function(...)
  level.message('WARNING: ', ...)

trim.space <- function(s) gsub('[[:space:]]','',s)
trim.blank <- function(s) gsub('[[:blank:]]','',s)
one.space <- function(s) gsub('[[:blank:]]+',' ',s)
one.line <- function(s) gsub('\n',' ',s)
pkg.vers <- function(s) gsub('_','.',s)
varassign <- function(varname, value) paste0(varname, '=\t', value)

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
base.packages <- c('R', base.packages.FAQ.5.1.2, base.packages.other)

licenses <- list()
licenses[['ACM']]                                    <- 'acm-license'
licenses[['ACM | file LICENSE']]                     <- 'acm-license\t# OR file LICENSE'
licenses[['APACHE']]                                 <- 'apache-1.1 OR apache-2.0'
licenses[['Apache License 2.0']]                     <- 'apache-2.0'
licenses[['Apache License (== 2.0)']]                <- 'apache-2.0'
licenses[['Apache License (== 2.0) | file LICENSE']] <- 'apache-2.0\t# OR file LICENSE'
licenses[['ARTISTIC']]                               <- 'artistic OR artistic-2.0'
licenses[['Artistic-2.0']]                           <- 'artistic-2.0'
licenses[['BSD']]                                    <- '2-clause-bsd OR modified-bsd OR original-bsd'
licenses[['BSD-2']]                                  <- '2-clause-bsd'
licenses[['BSD_2_clause + file LICENSE']]            <- '2-clause-bsd\t# + file LICENSE'
licenses[['BSD 3 clause']]                           <- 'modified-bsd'
licenses[['BSD 3 clause + file LICENSE']]            <- 'modified-bsd\t# + file LICENSE'
licenses[['BSD_3_clause + file LICENSE']]            <- 'modified-bsd\t# + file LICENSE'
licenses[['BSL-1.0']]                                <- 'boost-license'
licenses[['CC0']]                                    <- 'cc0-1.0-universal'
licenses[['GPL']]                                    <- 'gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3'
licenses[['GPL-1']]                                  <- 'gnu-gpl-v1'
licenses[['GPL-2']]                                  <- 'gnu-gpl-v2'
licenses[['GPL-2 | file LICENSE']]                   <- 'gnu-gpl-v2\t# OR file LICENSE'
licenses[['GPL-3']]                                  <- 'gnu-gpl-v3'
licenses[['GPL-2 | GPL-3']]                          <- 'gnu-gpl-v2 OR gnu-gpl-v3'
licenses[['GPL (>= 2)']]                             <- 'gnu-gpl-v2 OR gnu-gpl-v3'
licenses[['GPL (>= 2.0)']]                           <- 'gnu-gpl-v2 OR gnu-gpl-v3'
licenses[['GPL (>= 2) | file LICENSE']]              <- 'gnu-gpl-v2 OR gnu-gpl-v3\t# OR file LICENSE'
licenses[['GPL (>= 3)']]                             <- 'gnu-gpl-v3'
licenses[['LGPL']]                                   <- 'gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3'
licenses[['LGPL-2']]                                 <- 'gnu-lgpl-v2'
licenses[['LGPL-2.1']]                               <- 'gnu-lgpl-v2.1'
licenses[['LGPL-3']]                                 <- 'gnu-lgpl-v3'
licenses[['LGPL-3 + file LICENSE']]                  <- 'gnu-lgpl-v3\t# + file LICENSE'
licenses[['LGPL-2 | LGPL-3']]                        <- 'gnu-lgpl-v2 OR gnu-lgpl-v3'
licenses[['LGPL (>= 2)']]                            <- 'gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3'
licenses[['LUCENT']]                                 <- 'lucent'
licenses[['Lucent Public License']]                  <- 'lucent'
licenses[['MIT']]                                    <- 'mit'
licenses[['MIT + file LICENSE']]                     <- 'mit\t# + file LICENSE'
licenses[['MIT + file LICENSE | Unlimited']]         <- 'mit\t# + file LICENSE OR unlimited'
licenses[['MPL-1.0']]                                <- 'mpl-1.0'
licenses[['MPL-1.1']]                                <- 'mpl-1.1'
licenses[['MPL-2.0']]                                <- 'mpl-2.0'
licenses[['MPL-2.0 | file LICENSE']]                 <- 'mpl-2.0\t# OR file LICENSE'
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

end.paragraph <- function(lines)
  if (length(lines) > 0) append(lines, '') else lines

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
    '$')

  re.match_key <- paste0('^',
    re.skip_blank,
    re.optional_TODO,
    '(',re.key,')',
    re.skip_blank,
    re.operator,
    re.delimiter,
    re.value,
    '$')

  df$key_value <- grepl(re.match_key_value_line,df[,line])
  df$key <- sub(re.match_key,'\\2',df[,line])
  df$key[!df$key_value] <- NA
  df
}

categorize.depends <- function(df,line='line')
{
  df$depends <- df$key_value & df$key == 'DEPENDS'
  df$category[df$depends] <- unlist(sapply(strsplit(df[df$depends,line],'/',fixed=TRUE),'[',3))
  df
}

categorize.buildlink <- function(df,line='line')
{
  df$buildlink3.mk <- grepl('buildlink3.mk',df[,line])
  df$category[df$buildlink3.mk] <- unlist(sapply(strsplit(df[df$buildlink3.mk,line],'/',fixed=TRUE),'[',3))
  df
}

fix.continued.lines <- function(df,line='line')
{
  if (nrow(df) < 2)
    return(df)

  continued <- grepl('\\\\$', df[, line])
  continued_key_value <- df$key_value & continued

  if (FALSE %in% df[continued,'key_value'])
    level.warning('unhandled continued line(s)')

  for (i in 1 : (nrow(df) - 1))
    {
      if (!continued_key_value[i])
        next

      df[i, line] <- sub('[\t ]*\\\\$', '', df[i, line])
      df$key_value[i + 1] <- TRUE
      df$key[i + 1] <- df$key[i]
      df[i + 1, line] <- paste0(df$key[i], '+=', df[i + 1, line])
    }
  df
}

read.Makefile.as.dataframe <- function(filename = 'Makefile.orig')
{
  re_varassign <- paste0(
    '^',
    ' *',
    '(', '(?:#[\t ]*TODO[\t ]*:[\t ]*)*',')',  # comment
    '[^+=[:blank:]]+',  # varname
    '[\t ]*',
    '(', '[+=]+',')',  # operator
    '(', '[\t ]*',')',  # delimiter
    '(', '.*',')',
    '$')

  df <- read.file.as.dataframe(filename)

  df$order <- 1:nrow(df)
  df$category <- NA  # for DEPENDS lines

  df <- categorize.key_value(df)
  df <- fix.continued.lines(df)
  df <- categorize.depends(df)
  df <- categorize.buildlink(df)

  va <- df$key_value
  df$old_todo[va] <- sub(re_varassign, '\\1', df$line[va])
  df$operator[va] <- sub(re_varassign, '\\2', df$line[va])
  df$delimiter[va] <- sub(re_varassign, '\\3', df$line[va])
  df$old_value[va] <- sub(re_varassign, '\\4', df$line[va])
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

simplify.whitespace <- function(s) gsub('[[:blank:]]+', ' ', s)
remove.punctuation <- function(s) gsub('[,-]', '', s)
remove.quotes <- function(s) gsub('[\'`"]', '', s)
remove.articles <- function(s) gsub('\\b[Aa]n?\\b', '\\1', s)

case.insensitive.equals <- function(s1,s2)
{
  s1.lower <- tolower(simplify.whitespace(s1))
  s2.lower <- tolower(simplify.whitespace(s2))
  s1.lower == s2.lower
}

weakly.equals <- function(s1,s2)
{
  case.insensitive.equals(
    remove.articles(remove.quotes(remove.punctuation(s1))),
    remove.articles(remove.quotes(remove.punctuation(s2))))
}

pkgsrc.license <- function(s)
{
  license <- licenses[[s]]
  if (is.null(license)) license <- s else license
}

license <- function(s)
{
  license <- pkgsrc.license(s)
  old.license <- read.file.as.value('LICENSE')
  if (old.license != '' && old.license != license)
    license <- paste0(license,'\t# [R2pkg] previously: ',old.license)
  license
}

maintainer <- function(email)
{
  MAINTAINER <- read.file.as.value('MAINTAINER')
  if (MAINTAINER == '')
    MAINTAINER <- email
  MAINTAINER
}

find.Rcpp <- function(imps, deps)
  any(grepl('Rcpp', paste(imps, deps)))

buildlink3.mk <- function(imps,deps)
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
  if (find.Rcpp(imps,deps))
    {
      buildlink3.line <- '.include "../../devel/R-Rcpp/buildlink3.mk"'
      key <- 'devel'
      value <- buildlink3.line
      BUILDLINK3.MK <- rbind(BUILDLINK3.MK,data.frame(key=key,value=value))
    }
  BUILDLINK3.MK
}

varassigns <- function(key, values)
{
  fields <- list()
  for (l in values)
    {
      value <- unlist(l)
      if (value != '')
        fields <- append(fields, varassign(key, list(value)))
      else
        fields <- append(fields, list(''))
    }
  fields
}

categories <- function() basename(dirname(getwd()))

filter.imports <- function(s)
{
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
  s <- gsub('([[:alnum:]]+)[[:blank:]]+(\\([^\\)]*\\))?[[:blank:]]*,?','\\1 \\2,',s)
  imports <- na.omit(unlist(strsplit(s,',[[:blank:]]*')))
  imports <- trim.space(imports)
  imports <- filter.imports(imports)
  imports
}

make.dependency <- function(s)
{
  s <- gsub('\\)','',s)
  s <- gsub('-','.',s)
  unlist(strsplit(s,'\\('))
}

depends <- function(dependency) dependency[1]

depends.pkg <- function(dependency)
  Sys.glob(paste0('../../*/R-', depends(dependency)))

new.depends.pkg <- function(dependency)
  Sys.glob(paste0('../../wip/R-', depends(dependency)))

depends.pkg.fullname <- function(dependency,index=1)
{
  result <- system(paste('cd',depends.pkg(dependency)[index],'&& bmake show-var VARNAME=PKGNAME'),intern=TRUE)
  result
}

depends.pkg.vers <- function(dependency,index=1)
{
  result <- sub('^(.*)-([^-]*)$','\\2',depends.pkg.fullname(dependency,index))
  result
}

depends.vers <- function(dependency, index=1)
{
  if (length(dependency) == 2)
    trim.space(dependency[2])
  else
    trim.space(paste0('>=', depends.pkg.vers(dependency, index)))
}

depends.vers.2 <- function(dependency)
  ifelse(length(dependency) == 2, trim.space(dependency[2]), '>=???')

depends.dir <- function(dependency, index=1)
{
  fields <- strsplit(depends.pkg(dependency)[index], '/', fixed = TRUE)
  fields[[1]][3]
}

depends.line <- function(dependency,index=1)
{
  paste0('DEPENDS+=\tR-', depends(dependency), depends.vers(dependency, index), ':', depends.pkg(dependency)[index])
}

depends.line.2 <- function(dependency)
{
  result <- paste0('DEPENDS+=\tR-',depends,depends.vers.2(dependency),':../../???/R-',depends)
  result <- paste0(result,'\t# XXX - found')
  for (pkg in depends.pkg(dependency))
    result <- paste(result,pkg)
  result
}

buildlink3.file <- function(dependency, index=1)
  sprintf("%s/buildlink3.mk", depends.pkg(dependency)[index])

buildlink3.line <- function(dependency, index=1)
  sprintf('.include "%s"', buildlink3.file(dependency, index))

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
    level.warning('R-',arg.rpkg,' should not depend on a wip package: ',depends.pkg(dependency)[index])
}

update.dependency <- function(dependency, index=1)
{
  level.message('updating dependency for ', depends(dependency), ': ', depends.pkg(dependency)[index])
  command <- sprintf(
    'grep -E -q -e "%s" %s || (cd %s && %s %s %s)',
    depends(dependency), arg.packages_list,
    depends.pkg(dependency)[index], arg.r2pkg, arg.args, depends(dependency))
  error <- system(command)
  if (error != 0)
    level.warning('error updating dependency for ', depends(dependency))
}

make.depends <- function(imps,deps)
{
  warn_too_many_dependencies <- function(dependency) {
    level.warning(sprintf('too many dependencies found for %s: %s',
      depends(dependency), paste(depends.pkg(dependency))))
  }

  imports <- make.imports(imps,deps)
  # XXX  message('===> imports:')
  # XXX print(imports)
  DEPENDS <- data.frame()
  BUILDLINK3.MK <- buildlink3.mk(imps,deps)
  if (length(imports) > 0)
    {
      for (i in 1:length(imports))
        {
          dependency <- make.dependency(imports[i])
          depdirs <- depends.pkg(dependency)
          # XXX message('[ ',${LEVEL},' ] ===> ',i,' / ',length(imports),': ',depends(dependency))
          if (length(depdirs) == 0) # a dependency cannot be found
            {
              level.message('0 dependencies match ',dependency)
              if (arg.recursive)
                {
                  dir.create(path=dependency.dir(dependency),recursive=TRUE)
                  update.dependency(dependency)
                }
              else
                level.warning('dependency needed for ',depends(dependency))
            }
          else if (length(depdirs) == 1) # a unique dependency found
            {
              level.message('1 dependency matches ',dependency,': ',depdirs)
              message.wip.dependency(dependency)
              if (arg.recursive && arg.update)
                update.dependency(dependency)
              if (file.exists(buildlink3.file(dependency)))
                BUILDLINK3.MK <- rbind(BUILDLINK3.MK,data.frame(key=depends.dir(dependency),value=buildlink3.line(dependency)))
              else
                DEPENDS <- rbind(DEPENDS,data.frame(key=depends.dir(dependency),value=depends.line(dependency)))
            }
          else if (length(depdirs) == 2) # two dependencies found
            {
              index <- grep('/wip/',depdirs,invert=TRUE)
              level.message('2 dependencies match ',dependency,':',paste(' ',depdirs))
              # message('===> depends(dependency): ',depends(dependency))
              # message('===> depends.pkg(dependency):',paste(' ',d))
              # message('===> index: ',index)
              # message('===> buildlink3.line(): ',buildlink3.line(dependency,index))
              if (length(index) == 1) # a unique, non-wip, dependency found
                {
                  level.message('choosing unique non-wip dependency for ',dependency,': ',depdirs[index])
                  if (arg.recursive && arg.update)
                    update.dependency(dependency,index)
                  if (file.exists(buildlink3.file(dependency,index)))
                    BUILDLINK3.MK <- rbind(BUILDLINK3.MK,data.frame(key=depends.dir(dependency,index),value=buildlink3.line(dependency,index)))
                  else
                    DEPENDS <- rbind(DEPENDS,data.frame(key=depends.dir(dependency,index),value=depends.line(dependency,index)))
                }
              else
                {
                  level.message('no unique non-wip dependency matches')
                  warn_too_many_dependencies(dependency)
                  DEPENDS <- rbind(DEPENDS,data.frame(key='???',value=depends.line.2(dependency)))
                }
            }
          else  # more than 2 dependencies found
            {
              level.message(length(depdirs),' dependencies match ',dependency,':',paste(' ',depdirs))
              warn_too_many_dependencies(dependency)
              DEPENDS <- rbind(DEPENDS,data.frame(key='???',value=depends.line.2(dependency)))
            }
          if (length(new.depends.pkg(dependency)) > 0)
            system(paste('echo', depends(dependency), arg.rpkg, '>>', arg.dependency_list))
        }
    }
  DEPENDS <- as.sorted.list(DEPENDS)
  DEPENDS <- end.paragraph(DEPENDS)
  BUILDLINK3.MK <- as.sorted.list(BUILDLINK3.MK)
  result <- list(DEPENDS,BUILDLINK3.MK)
  result
}

use_languages <- function(imps, deps)
  if (find.Rcpp(imps, deps)) 'c c++' else '# none'

copy.description <- function(connection)
{
  description <- readLines(connection)
  writeLines(description,con='DESCRIPTION')
}

write.Makefile <- function(metadata)
{
  CATEGORIES    <- varassign('CATEGORIES', categories())
  MAINTAINER    <- varassign('MAINTAINER', maintainer(arg.maintainer_email))
  COMMENT       <- varassign('COMMENT', one.line(metadata$Title))
  LICENSE       <- varassign('LICENSE', license(metadata$License))
  R_PKGNAME     <- varassign('R_PKGNAME', one.line(metadata$Package))
  R_PKGVER      <- varassign('R_PKGVER', one.line(metadata$Version))
  USE_LANGUAGES <- varassign('USE_LANGUAGES', use_languages(metadata$Imports, metadata$Depends))
  dependencies  <- make.depends(metadata$Imports, metadata$Depends)
  depends       <- dependencies[1]
  buildlink3    <- dependencies[2]

  lines <- c(
    mkcvsid,
    '',
    R_PKGNAME,
    R_PKGVER,
    CATEGORIES,
    '',
    MAINTAINER,
    COMMENT,
    LICENSE,
    '',
    depends,
    USE_LANGUAGES,
    '',
    '.include "../../math/R/Makefile.extension"',
    buildlink3,
    '.include "../../mk/bsd.pkg.mk"',
    recursive = TRUE)

  writeLines(lines, 'Makefile')
}

construct.line <- function(df,key,value)
{
  key <- df[df$key==key,'key']
  operator <- df[df$key==key,'operator']
  delimiter <- df[df$key==key,'delimiter']
  value <- df[df$key==key,value]
  df$new_line[df$key==key] <- paste0(key,operator,delimiter,value)
  df
}

element <- function(mklines, varname, field, quiet=FALSE)
{
  i <- match(varname, mklines$key, 0)
  if (i != 0 && mklines$key_value[i])
    return(mklines[i, field])

  if (!quiet)
    {
      if (i == 0)
        level.warning(varname, ' not found')
      else
        level.warning(varname, ' is not a key-value field')
    }
  '???'
}

make.categories <- function(mklines)
{
  directory <- basename(dirname(getwd()))
  categories <- unlist(element(mklines, 'CATEGORIES', 'old_value'))
  categories <- unlist(strsplit(categories, '[[:blank:]]+'))
  categories <- c(directory, categories)
  categories <- categories[categories != 'R']
  if (directory != 'wip')
    categories <- categories[categories != 'wip']
  categories <- categories[!duplicated(categories)]
  paste(categories, collapse = ' ')
}

make.maintainer <- function(mklines)
{
  old.maintainer <- element(mklines, 'MAINTAINER', 'old_value')
  new.maintainer <- element(mklines, 'MAINTAINER', 'new_value')
  if (old.maintainer == '') new.maintainer else old.maintainer
}

make.comment <- function(mklines)
{
  old.comment <- element(mklines, 'COMMENT', 'old_value')
  new.comment <- element(mklines, 'COMMENT', 'new_value')
  if (weakly.equals(old.comment, new.comment))
    old.comment
  else
    paste0(old.comment, '\t# [R2pkg] updated to: ', new.comment)
}

make.new_license <- function(df,license)
{
  new_license <- licenses[[license]]
  if (is.null(new_license))
      new_license <- license
  df$new_value[df$key == 'LICENSE'] <- new_license
  df
}

license.in.pkgsrc <- function(license) { license %in% sapply(licenses,'[',1) }

make.license <- function(df)
{
  # message('===> make.license():')
  old_license <- element(df,'LICENSE','old_value')
  old_todo <- element(df,'LICENSE','old_todo')
  new_license <- element(df,'LICENSE','new_value')

  old_known <- license.in.pkgsrc(old_license)
  new_known <- license.in.pkgsrc(new_license)

  if (old_known && new_known)
    {
      if (case.insensitive.equals(old_license,new_license))
        {
          license <- old_license
          todo <- old_todo
        }
      else
        {
          license <- paste0(new_license,'\t# [R2pkg] previously: ',old_license)
          todo <- old_todo
        }
    }
  else if (old_known && !new_known)
    {
      license <- paste0(old_license,'\t# [R2pkg] updated to: ',new_license)
      todo <- '# TODO: '
    }
  else if (!old_known && new_known)
    {
      license <- paste0(new_license,'\t# [R2pkg] previously: ',old_license)
      todo <- ''
    }
  else
    {
      license <- paste0(new_license,'\t# [R2pkg] previously: ',old_license)
      todo <- '# TODO: '
    }

  df$value[df$key == 'LICENSE'] <- license
  df$todo[df$key == 'LICENSE'] <- todo

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

mklines.update_with_metadata <- function(df, metadata)
{
  df$new_value <- NA

  df <- make.new_license(df, metadata$License)

  df$new_value[df$key == 'CATEGORIES'] <- categories()
  df$new_value[df$key == 'MAINTAINER'] <- arg.maintainer_email
  df$new_value[df$key == 'COMMENT'] <- one.line(metadata$Title)
  df$new_value[df$key == 'R_PKGVER'] <- one.line(metadata$Version)
  df
}

mklines.update_value <- function(df)
{
  df$value <- NA
  df$todo <- ''
  df <- make.license(df)
  df$value[df$key == 'CATEGORIES'] <- make.categories(df)
  df$value[df$key == 'MAINTAINER'] <- make.maintainer(df)
  df$value[df$key == 'COMMENT'] <- make.comment(df)
  df$value[df$key == 'R_PKGVER'] <- make.r_pkgver(df)
  df
}

mklines.update_new_line <- function(df)
{
  df$new_line <- df$line

  va <- df$key_value & !is.na(df$value)
  df$new_line[va] <- paste0(
    df$todo[va], df$key[va], df$operator[va], df$delimiter[va], df$value[va])

  df
}

mklines.annotate_distname <- function(mklines)
{
  match <- grepl('^[[:blank:]]*DISTNAME', mklines$new_line)
  line <- mklines$new_line[match]
  value <- sub('^[[:blank:]]*DISTNAME[[:blank:]]*=[[:blank:]]*', '', line)
  comment <- sprintf(
    '\t# [R2pkg] replace this line with %s and %s as first stanza',
    paste0('R_PKGNAME=', sub('_.+$', '', value)),
    paste0('R_PKGVER=', sub('^.+_', '', value)))
  mklines$new_line[match] <- paste0(line, comment)
  mklines
}

mklines.remove_lines_before_update <- function(mklines)
{
  remove <- (
    grepl('^[[:blank:]]*MASTER_SITES', mklines$new_line) |
    grepl('^[[:blank:]]*HOMEPAGE', mklines$new_line) |
    grepl('^[[:blank:]]*BUILDLINK_ABI_DEPENDS', mklines$new_line) |
    grepl('^[[:blank:]]*BUILDLINK_API_DEPENDS', mklines$new_line))
  mklines[!remove,]
}

mklines.reassign_order <- function(mklines)
{
  r_pkgname.order <- element(mklines, 'R_PKGNAME', 'order')
  categories.order <- element(mklines, 'CATEGORIES', 'order')
  if (r_pkgname.order > categories.order)
    {
      r_pkgname.index <- mklines$key == 'R_PKGNAME'
      r_pkgname.index[is.na(r_pkgname.index)] <- FALSE
      r_pkgver.index <- mklines$key == 'R_PKGVER'
      r_pkgver.index[is.na(r_pkgver.index)] <- FALSE
      mklines[r_pkgname.index, 'order'] <- categories.order - 0.2
      mklines[r_pkgver.index, 'order'] <- categories.order - 0.1
    }
  mklines
}

conflicts <- function(pkg)
{
  conflict <- sprintf('R>=%s.%s', R.version$major, R.version$minor)
  conflicts <- list()
  if (pkg %in% base.packages)
    {
      conflicts <- append(conflicts, varassign('CONFLICTS', conflict))
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
      c <- conflicts(metadata$Package)
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
  if (TRUE %in% df$depends)
    df.depends <- data.frame(new_line=df[df$depends,'line'],stringsAsFactors=FALSE)
  for (line in DEPENDS)
    df.depends <- rbind(df.depends,data.frame(new_line=line,stringsAsFactors=FALSE))
  if (nrow(df.depends) > 0)
    {
      df.depends$category <- NA
      df.depends$buildlink3.mk <- FALSE
      df.depends <- categorize.key_value(df.depends,'new_line')
      df.depends <- categorize.depends(df.depends,'new_line')
      df.depends$key_value <- NULL
      df.depends$key <- NULL
      df.depends <- df.depends[!duplicated(df.depends),]
      df.depends$order <- find.order(df,'depends','order')
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
  if (TRUE %in% df$buildlink3.mk)
    df.buildlink3.mk <- data.frame(new_line=df[df$buildlink3.mk,'line'],stringsAsFactors=FALSE)
  for (line in BUILDLINK3.MK)
    df.buildlink3.mk <- rbind(df.buildlink3.mk,data.frame(new_line=line,stringsAsFactors=FALSE))
  if (nrow(df.buildlink3.mk) > 0)
    {
      df.buildlink3.mk$category <- NA
      df.buildlink3.mk$depends <- FALSE
      df.buildlink3.mk <- categorize.buildlink(df.buildlink3.mk,'new_line')
      df.buildlink3.mk <- df.buildlink3.mk[!duplicated(df.buildlink3.mk),]
      df.buildlink3.mk$order <- find.order(df,'buildlink3.mk','order')
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
  df.makefile <- df[!df$depends & !df$buildlink3.mk,fields]
  df.makefile <- rbind(df.makefile,df.conflicts,df.depends,df.buildlink3.mk)
  df.makefile <- df.makefile[order(df.makefile$order,df.makefile$category,df.makefile$new_line),]
  df.makefile <- df.makefile[!adjacent.duplicates(df.makefile$new_line),]
  df.makefile
}

update.Makefile <- function(metadata)
{
  DEPENDENCIES  <- make.depends(metadata$Imports,metadata$Depends)
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
  df <- mklines.update_with_metadata(df, metadata)
  df <- mklines.update_value(df)
  df <- mklines.update_new_line(df)
  df <- mklines.annotate_distname(df)
  df <- mklines.remove_lines_before_update(df)
  df <- mklines.reassign_order(df)

  df.conflicts <- make.df.conflicts(df,metadata)
  df.depends <- make.df.depends(df,DEPENDS)
  df.buildlink3 <- make.df.buildlink3(df,BUILDLINK3.MK)
  df.makefile <- make.df.makefile(df,df.conflicts,df.depends,df.buildlink3)

  write(df.makefile[, 'new_line'], 'Makefile')
}

create.Makefile <- function(metadata)
{
  if (arg.update && file.exists('Makefile.orig'))
    update.Makefile(metadata)
  else
    write.Makefile(metadata)
}

create.DESCR <- function(metadata) {
  descr <- strwrap(metadata$Description, width = 71)
  write(descr, 'DESCR')
}

make.metadata <- function(description.filename)
{
  fields <- c('Package', 'Version', 'Title', 'Description', 'License', 'Imports', 'Depends')
  metadata <- as.list(read.dcf(description.filename, fields))
  names(metadata) <- fields
  metadata
}

main <- function()
{
  Sys.setlocale('LC_ALL', 'C')

  error <- download.file(url=arg.rpkg_description_url,destfile='DESCRIPTION',quiet=arg.quiet_curl,method='curl')
  if (error)
    {
      message('ERROR: Downloading the DESCRIPTION file for ',arg.rpkg,' failed;')
      message('       perhaps the package no longer exists?')
      quit(save='no',status=error)
    }

  metadata <- make.metadata('DESCRIPTION')
  create.Makefile(metadata)
  create.DESCR(metadata)
}
