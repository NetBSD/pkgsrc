# $NetBSD: R2pkg_test.R,v 1.6 2019/10/18 16:07:53 rillig Exp $
#
# Copyright (c) 2019
#	Roland Illig.  All rights reserved.
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

source('R2pkg.R')
library(testthat)
library(withr)

mkcvsid = paste0('# $', 'NetBSD$')

# TODO: use a test fixture for setting these
arg.recursive <- FALSE
arg.update <- FALSE

package.dir <- file.path(Sys.getenv('PKGSRCDIR'), 'pkgtools', 'R2pkg')

expect_printed <- function(obj, ...) {
    out <- ''
    with_output_sink(textConnection('out', 'w', local = TRUE), print(obj))
    expect_equal(length(out), length(c(...)))
    expect_equal(!!out, !!c(...))
}

linesConnection <- function(...)
    textConnection(paste0(c(...), collapse = '\n'))

test_that('linesConnection', {
    lines <- readLines(linesConnection('1', '2', '3'))

    expect_equal(lines, c('1', '2', '3'))
})

test_that('level.message', {
    output <- ''
    mock_message <- function(...) output <<- paste0(output, ..., '\n')

    arg.level <<- 123  # XXX: should use with_environment instead
    with_mock(message = mock_message, {
        level.message('mess', 'age', ' text')
    })

    expect_equal(output, '[ 123 ] message text\n')
})

test_that('level.warning', {
    output <- ''
    mock_message <- function(...) output <<- paste0(output, ..., '\n')

    arg.level <<- 321  # XXX: should use with_environment instead
    with_mock(message = mock_message, {
        level.warning('mess', 'age', ' text')
    })

    expect_equal(output, '[ 321 ] WARNING: message text\n')
})

test_that('trim.space', {
    expect_equal(trim.space(' hello, \t\nworld '), 'hello,world')
})

test_that('trim.blank', {
    expect_equal(trim.blank(' hello, \t\nworld '), 'hello,\nworld')
})

test_that('one.space', {
    expect_equal(
        one.space(' \t\nhello, \t\nworld \t\n'),
        ' \nhello, \nworld \n')
})

test_that('one.line', {
    expect_equal(
        one.line(' \t\nhello, \t\nworld \t\n'),
        ' \t hello, \t world \t ')
})

test_that('pkg.vers', {
    expect_equal(pkg.vers('1_0-2.3'), '1.0-2.3')
})

test_that('varassign', {
    expect_equal(varassign('VAR', 'value'), 'VAR=\tvalue')
})

test_that('adjacent.duplicates', {
    expect_equal(
    adjacent.duplicates(c(1, 2, 2, 2, 3, 3, 4)),
    c(FALSE, FALSE, TRUE, TRUE, FALSE, TRUE, FALSE)
    )
})

test_that('paste2', {
    expect_equal(paste2(NA, NA), '')
    expect_equal(paste2('', NA), '')
    expect_equal(paste2(NA, ''), '')
    expect_equal(paste2('', ''), ' ')
    expect_equal(paste2('one', 'two'), 'one two')
})

test_that('end.paragraph', {
    expect_equal(end.paragraph(list()), list())
    expect_equal(end.paragraph(list('line')), list('line', ''))
})

test_that('as.sorted.list', {
    expect_equal(as.sorted.list(data.frame()), list())

    expect_equal(
    as.sorted.list(data.frame(
    varnames = c('A', 'B', 'B', 'B', 'A'),
    values = c('1', '3', '2', '1', '1'))),
    list('1', '1', '2', '3'))
})

test_that('read.file.as.dataframe', {
    content <- linesConnection(
        'VAR=value',
        'VAR2=value2')

    df <- read.file.as.dataframe(content)

    expect_equal(length(df$line), 2)
    expect_equal(df$line[[1]], 'VAR=value')
    expect_equal(df$line[[2]], 'VAR2=value2')
})

# test_that('categorize.key_value', {
# })

# test_that('categorize.depends', {
# })

# test_that('categorize.buildlink', {
# })

# test_that('fix.continued.lines', {
# })

test_that('read.Makefile.as.dataframe', {
    df <- read.Makefile.as.dataframe(linesConnection(
        '# comment',
        'VAR= value',
        '',
        '.include "other.mk"',
        '.if 0',
        '.endif'))

    expect_printed(df,
        '                 line order category key_value  key depends buildlink3.mk',
        '1           # comment     1       NA     FALSE <NA>   FALSE         FALSE',
        '2          VAR= value     2       NA      TRUE  VAR   FALSE         FALSE',
        '3                         3       NA     FALSE <NA>   FALSE         FALSE',
        '4 .include "other.mk"     4       NA     FALSE <NA>   FALSE         FALSE',
        '5               .if 0     5       NA     FALSE <NA>   FALSE         FALSE',
        '6              .endif     6       NA     FALSE <NA>   FALSE         FALSE',
        '  operator delimiter old_value old_todo',
        '1     <NA>      <NA>      <NA>     <NA>',
        '2        =               value         ',
        '3     <NA>      <NA>      <NA>     <NA>',
        '4     <NA>      <NA>      <NA>     <NA>',
        '5     <NA>      <NA>      <NA>     <NA>',
        '6     <NA>      <NA>      <NA>     <NA>')
})

test_that('read.file.as.list can read an empty file', {
    filename <- ''
    local_tempfile('filename')
    file.create(filename)

    lines <- read.file.as.list(filename)

    expect_equal(lines, list())
})

test_that('read.file.as.list can read lines from a file', {
    filename <- ''
    local_tempfile('filename')
    writeLines(c('first', 'second \\', 'third'), filename)

    lines <- read.file.as.list(filename)

    expect_equal(lines, list('first', 'second \\', 'third'))
})

test_that('read.file.as.value, exactly 1 variable assignment, no space', {
    filename <- ''
    local_tempfile('filename')
    writeLines(c('VAR=value'), filename)

    str <- read.file.as.value(filename)

    expect_equal(str, NA_character_)  # FIXME
})

test_that('read.file.as.value, exactly 1 variable assignment', {
    filename <- ''
    local_tempfile('filename')
    writeLines(c('VAR=\tvalue'), filename)

    str <- read.file.as.value(filename)

    expect_equal(str, 'value')
})

test_that('read.file.as.value, commented variable assignment', {
    filename <- ''
    local_tempfile('filename')
    writeLines(c('#VAR=\tvalue'), filename)

    str <- read.file.as.value(filename)

    # TODO: Check whether commented variables should really be considered.
    expect_equal(str, 'value')
})

test_that('read.file.as.value, multiple variable assignments', {
    filename <- ''
    local_tempfile('filename')
    writeLines(c('VAR=\tvalue', 'VAR=\tvalue2'), filename)

    str <- read.file.as.value(filename)

    expect_equal(str, '')
})

# test_that('read.file.as.values', {
# })

# test_that('simplify.whitespace', {
# })

# test_that('remove.punctuation', {
# })

# test_that('remove.quotes', {
# })

# test_that('remove.articles', {
# })

# test_that('case.insensitive.equals', {
# })

# test_that('weakly.equals', {
# })

# test_that('new.field.if.different', {
# })

# test_that('pkgsrc.license', {
# })

# test_that('package', {
# })

# test_that('version', {
# })

# test_that('comment', {
# })

# test_that('use.tools', {
# })

# test_that('license', {
# })

# test_that('maintainer', {
# })

test_that('find.Rcpp', {
    expect_equal(find.Rcpp(list(), list()), FALSE)
    expect_equal(find.Rcpp(list('Other'), list('Other')), FALSE)

    expect_equal(find.Rcpp(list('Rcpp'), list()), TRUE)
    expect_equal(find.Rcpp(list(), list('Rcpp')), TRUE)
})

# test_that('buildlink3.mk', {
# })

test_that('varassigns', {
    expect_equal(
    varassigns('VARNAME', c('value1', 'value2', '', 'value3')),
    list(
    'VARNAME=\tvalue1',
    'VARNAME=\tvalue2',  # FIXME: This doesn't make sense.
    '',
    'VARNAME=\tvalue3'))
})

# test_that('categories', {
# })

# test_that('description', {
# })

# test_that('filter.imports', {
# })

test_that('make.imports', {
    expect_equal(
        make.imports(NA_character_, NA_character_),
        character(0))

    expect_equal(
        make.imports('first (>= 1.0)', 'second'),
        c('first(>=1.0)', 'second'))

    expect_equal(
        make.imports('first(>=1)', 'second(>=1)'),
        c('first(>=1)second(>=1)'))

    expect_equal(
        make.imports('first(>=1) second(>=1)', NA_character_),
        c('first(>=1)second(>=1)'))
})

test_that('make.dependency', {
    expect_equal(make.dependency('pkgname'), c('pkgname'))
    expect_equal(make.dependency('pkgname(>=1.0)'), c('pkgname', '>=1.0'))

    # undefined behavior
    expect_equal(make.dependency('pkgname (>= 1.0)'), c('pkgname ', '>= 1.0'))
})

# test_that('depends', {
# })

# test_that('depends.pkg', {
# })

# test_that('new.depends.pkg', {
# })

# test_that('depends.pkg.fullname', {
# })

# test_that('depends.pkg.name', {
# })

# test_that('depends.pkg.vers', {
# })

# test_that('depends.vers', {
# })

# test_that('depends.vers.2', {
# })

# test_that('depends.dir', {
# })

# test_that('depends.line', {
# })

# test_that('depends.line.2', {
# })

test_that('buildlink3.file with matching version number', {
    local_dir(package.dir)
    dependency <- make.dependency('bitops(>=0.1)')

    bl3 <- buildlink3.file(dependency)

    expect_equal(bl3, '../../math/R-bitops/buildlink3.mk')
})

# The version number of the dependency is not checked against
# the resolved buildlink3 file.
test_that('buildlink3.file with too high version number', {
    local_dir(package.dir)
    dependency <- make.dependency('bitops(>=1000.0)')

    bl3 <- buildlink3.file(dependency)

    expect_equal(bl3, '../../math/R-bitops/buildlink3.mk')
})

# test_that('buildlink3.line', {
# })

# test_that('dependency.dir', {
# })

# test_that('message.wip.dependency', {
# })

# test_that('message.too.many.dependencies', {
# })

# test_that('update.dependency', {
# })

# test_that('make.depends', {
# })

test_that('use.languages', {
    languages <- use.languages(list(), list())

    expect_equal(languages, c('# none', ''))
})

test_that('use.languages with Rcpp as dependency', {
    languages <- use.languages(list('Rcpp(>=0)'), list())
    expected <- list('c cpp', '')

    #expect_equal(languages, expected)
})

# test_that('copy.description', {
# })

# test_that('write.Makefile', {
# })

# test_that('construct.line', {
# })

# test_that('element', {
# })

# test_that('make.categories', {
# })

# test_that('make.maintainer', {
# })

# test_that('make.comment', {
# })

# test_that('make.new_license', {
# })

# test_that('license.marked.todo', {
# })

# test_that('license.in.pkgsrc', {
# })

# test_that('make.license', {
# })

# test_that('make.r_pkgver', {
# })

# test_that('find.order', {
# })

# test_that('write.makefile', {
# })

test_that('update.Makefile.with.metadata', {
    df <- read.Makefile.as.dataframe(linesConnection(
        'CATEGORIES=',
        'MAINTAINER=',
        'COMMENT=',
        'R_PKGVER='))
    metadata = list(Title = 'Package comment', Version = '19.3', License = 'license')

    updated <- update.Makefile.with.metadata(df, metadata)

    expect_printed(updated,
        '         line order category key_value        key depends buildlink3.mk',
        '1 CATEGORIES=     1       NA      TRUE CATEGORIES   FALSE         FALSE',
        '2 MAINTAINER=     2       NA      TRUE MAINTAINER   FALSE         FALSE',
        '3    COMMENT=     3       NA      TRUE    COMMENT   FALSE         FALSE',
        '4   R_PKGVER=     4       NA      TRUE   R_PKGVER   FALSE         FALSE',
        '  operator delimiter old_value old_todo       new_value',
        '1        =                                        R2pkg',
        '2        =                                             ',
        '3        =                              Package comment',
        '4        =                                         19.3')
})

# If the variable has been removed from the Makefile, it is not updated.
test_that('update.Makefile.with.metadata without CATEGORIES', {
    df <- read.Makefile.as.dataframe(linesConnection(
        'MAINTAINER=',
        'COMMENT=',
        'R_PKGVER='))
    metadata = list(Title = 'Package comment', Version = '19.3', License = 'license')

    updated <- update.Makefile.with.metadata(df, metadata)

    expect_printed(updated,
        '         line order category key_value        key depends buildlink3.mk',
        '1 MAINTAINER=     1       NA      TRUE MAINTAINER   FALSE         FALSE',
        '2    COMMENT=     2       NA      TRUE    COMMENT   FALSE         FALSE',
        '3   R_PKGVER=     3       NA      TRUE   R_PKGVER   FALSE         FALSE',
        '  operator delimiter old_value old_todo       new_value',
        '1        =                                             ',
        '2        =                              Package comment',
        '3        =                                         19.3')
})

# test_that('update.Makefile.with.new.values', {
# })

# test_that('update.Makefile.with.new.line', {
# })

# test_that('annotate.distname.in.Makefile', {
# })

# test_that('annotate.Makefile', {
# })

# test_that('remove.master.sites.from.Makefile', {
# })

# test_that('remove.homepage.from.Makefile', {
# })

# test_that('remove.buildlink.abi.depends.from.Makefile', {
# })

# test_that('remove.buildlink.api.depends.from.Makefile', {
# })

# test_that('remove.lines.from.Makefile', {
# })

# test_that('reassign.order', {
# })

test_that('conflicts', {
    expect_equal(conflicts('UnknownPackage'), list())

    expect_equal(
        conflicts('lattice'),
        list('CONFLICTS=\tR>=3.6.1', ''))

    expect_equal(
        conflicts(c('lattice', 'methods', 'general', 'UnknownPackage')),
        list('CONFLICTS=\tR>=3.6.1', ''))
})

# test_that('conflicts.order', {
# })

# test_that('make.df.conflicts', {
# })

# test_that('make.df.depends', {
# })

# test_that('make.df.buildlink3', {
# })

# test_that('make.df.makefile', {
# })

test_that('update.Makefile', {
    local_dir(tempdir())
    local_mock('system', function(...) {
        expect_printed(list(...), 'asdf')
        ''
    })
    writeLines(
        c(
            mkcvsid,
            '',
            '.include "../../mk/bsd.pkg.mk"'),
        'Makefile.orig')
    writeLines(
        c(
            'Package: pkgname',
            'Version: 1.0',
            'Depends: dep1 dep2(>=2.0)'),
        'DESCRIPTION')
    metadata <- make.metadata('DESCRIPTION')
    expect_printed(
        as.data.frame(metadata),
        '  Package Version Title Description License Imports          Depends',
        '1 pkgname     1.0  <NA>        <NA>    <NA>    <NA> dep1 dep2(>=2.0)')
    expect_printed(metadata$Imports, '[1] NA')
    expect_printed(metadata$Depends, '[1] "dep1 dep2(>=2.0)"')
    expect_printed(
        paste2(metadata$Imports, metadata$Depends),
        '[1] "dep1 dep2(>=2.0)"')
    expect_printed(
        make.imports(metadata$Imports, metadata$Depends),
        '[1] "dep1"        "dep2(>=2.0)"')
    FALSE && expect_printed(
        make.depends(metadata$Imports, metadata$Depends),
        '[1] "dep1"        "dep2(>=2.0)"')

    FALSE && update.Makefile(metadata)

    FALSE && expect_equal(
        c(
            mkcvsid,
            '',
            'asdf'),
        readLines('Makefile'))
})

# test_that('create.Makefile', {
# })

test_that('create.DESCR', {
    local_dir(tempdir())
    metadata <- make.metadata(linesConnection(
        'Description: First line',
        ' .',
        ' Second paragraph',
        ' has 2 lines'))

    create.DESCR(metadata)

    lines <- readLines('DESCR', encoding = 'UTF-8')
    expect_equal(lines, c(
        'First line',
        '',
        'Second paragraph has 2 lines'
    ))
})

test_that('create.DESCR for a package without Description', {
    local_dir(tempdir())
    metadata <- make.metadata(linesConnection('Package: pkgname'))

    create.DESCR(metadata)

    lines <- readLines('DESCR', encoding = 'UTF-8')
    expect_equal(lines, c('NA'))  # FIXME
})

test_that('make.metadata', {
    description <- paste(
        c(
            'Package: pkgname',
            'Version: 1.0',
            'Imports: dep1 other'
        ),
        collapse = '\n')

    metadata <- make.metadata(textConnection(description))

    expect_equal(metadata$Package, 'pkgname')
    expect_equal(metadata$Version, '1.0')
    expect_equal(metadata$Imports, 'dep1 other')
    expect_equal(metadata$Depends, NA_character_)
})

# test_that('main', {
# })
