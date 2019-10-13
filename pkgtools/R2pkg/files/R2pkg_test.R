# $NetBSD: R2pkg_test.R,v 1.1 2019/10/13 18:13:03 rillig Exp $
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

test_that('make.imports', {
    imports <- make.imports('first (>= 1.0)', 'second')

    expect_equal(imports, c('first(>=1.0)', 'second'))
})

test_that('make.dependency', {
    imports <- make.dependency('first(>=1.0)')

    expect_equal(imports, c('first', '>=1.0'))
})

test_that('buildlink3.file with matching version number', {
    local_dir('..')
    dependency <- make.dependency('ellipsis(>=0.1)')

    bl3 <- buildlink3.file(dependency)

    expect_equal(bl3, '../../math/R-ellipsis/buildlink3.mk')
})

# The version number of the dependency is not checked against
# the resolved buildlink3 file.
test_that('buildlink3.file with too high version number', {
    local_dir('..')
    dependency <- make.dependency('ellipsis(>=1000.0)')

    bl3 <- buildlink3.file(dependency)

    expect_equal(bl3, '../../math/R-ellipsis/buildlink3.mk')
})

test_that('level.warning', {
    output <- ''
    mock_message <- function(...) output <<- paste0(output, ..., '\n')

    arg.level <<- 123  # XXX: should use with_environment instead
    with_mock(message = mock_message, {
        level.warning('mess', 'age', ' text')
    })

    expect_equal(output, '[ 123 ] WARNING: message text\n')
})

test_that('read.file.as.dataframe', {
    content <- textConnection('VAR=value\nVAR2=value2\n')

    df <- read.file.as.dataframe(content)

    expect_equal(length(df$line), 3)
    expect_equal(df$line[[1]], 'VAR=value')
    expect_equal(df$line[[2]], 'VAR2=value2')
    expect_equal(df$line[[3]], '')
})

test_that('read.Makefile.as.dataframe', {
    lines <- c(
        '# comment',
        'VAR= value',
        '',
        '.include "other.mk"',
        '.if 0',
        '.endif'
    )
    content <- paste0(paste(lines, collapse = '\n'), '\n')
    expect_equal(content, '# comment\nVAR= value\n\n.include "other.mk"\n.if 0\n.endif\n')

    df <- read.Makefile.as.dataframe(textConnection(content))

    out <- ''
    with_output_sink(textConnection('out', 'w', local = TRUE), {
        print(df)
    })

    expected.out <- c(
        '                 line order category key_value  key depends buildlink3.mk',
        '1           # comment     1       NA     FALSE <NA>   FALSE         FALSE',
        '2          VAR= value     2       NA      TRUE  VAR   FALSE         FALSE',
        '3                         3       NA     FALSE <NA>   FALSE         FALSE',
        '4 .include "other.mk"     4       NA     FALSE <NA>   FALSE         FALSE',
        '5               .if 0     5       NA     FALSE <NA>   FALSE         FALSE',
        '6              .endif     6       NA     FALSE <NA>   FALSE         FALSE',
        '7                         7       NA     FALSE <NA>   FALSE         FALSE',
        '  operator delimiter old_value old_todo',
        '1     <NA>      <NA>      <NA>     <NA>',
        '2        =               value         ',
        '3     <NA>      <NA>      <NA>     <NA>',
        '4     <NA>      <NA>      <NA>     <NA>',
        '5     <NA>      <NA>      <NA>     <NA>',
        '6     <NA>      <NA>      <NA>     <NA>',
        '7     <NA>      <NA>      <NA>     <NA>'
    )
    expect_equal(out, expected.out)
})
