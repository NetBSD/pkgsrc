/*-
 * Copyright (c) 2003-2007 Tim Kientzle
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "test.h"
__FBSDID("$FreeBSD$");

#include "../cpio.h"

/*
 * Verify that the pattern matcher implements the wildcard logic specified
 * in SUSv2 for the cpio command.  This is essentially the
 * shell glob syntax:
 *   * - matches any sequence of chars, including '/'
 *   ? - matches any single char, including '/'
 *   [...] - matches any of a set of chars, '-' specifies a range,
 *        initial '!' is undefined
 *
 * The specification in SUSv2 is a bit incomplete, I assume the following:
 *   Trailing '-' in [...] is not special.
 *   Leading ']' in [...] is not special.
 */

DEFINE_TEST(test_pathmatch)
{
	assertEqualInt(1, pathmatch("*",""));
	assertEqualInt(1, pathmatch("*","a"));
	assertEqualInt(1, pathmatch("*","abcd"));
	/* SUSv2: * matches / */
	assertEqualInt(1, pathmatch("*","abcd/efgh/ijkl"));
	assertEqualInt(1, pathmatch("abcd*efgh/ijkl","abcd/efgh/ijkl"));
	assertEqualInt(1, pathmatch("abcd***efgh/ijkl","abcd/efgh/ijkl"));
	assertEqualInt(1, pathmatch("abcd***/efgh/ijkl","abcd/efgh/ijkl"));
	assertEqualInt(0, pathmatch("?", ""));
	assertEqualInt(1, pathmatch("?", "a"));
	assertEqualInt(0, pathmatch("?", "ab"));
	assertEqualInt(1, pathmatch("?", "."));
	assertEqualInt(1, pathmatch("?", "?"));
	assertEqualInt(1, pathmatch("a", "a"));
	assertEqualInt(0, pathmatch("a", "ab"));
	assertEqualInt(0, pathmatch("a", "ab"));
	assertEqualInt(1, pathmatch("a?c", "abc"));
	/* SUSv2: ? matches / */
	assertEqualInt(1, pathmatch("a?c", "a/c"));
	assertEqualInt(1, pathmatch("a?*c*", "a/c"));
	assertEqualInt(1, pathmatch("*a*", "a/c"));
	assertEqualInt(1, pathmatch("*a*", "/a/c"));
	assertEqualInt(1, pathmatch("*a*", "defaaaaaaa"));
	assertEqualInt(0, pathmatch("*a*", "defghi"));
	assertEqualInt(1, pathmatch("abc[def", "abc[def"));
	assertEqualInt(0, pathmatch("abc[def]", "abc[def"));
	assertEqualInt(0, pathmatch("abc[def", "abcd"));
	assertEqualInt(1, pathmatch("abc[def]", "abcd"));
	assertEqualInt(1, pathmatch("abc[def]", "abce"));
	assertEqualInt(1, pathmatch("abc[def]", "abcf"));
	assertEqualInt(0, pathmatch("abc[def]", "abcg"));
	assertEqualInt(1, pathmatch("abc[d*f]", "abcd"));
	assertEqualInt(1, pathmatch("abc[d*f]", "abc*"));
	assertEqualInt(0, pathmatch("abc[d*f]", "abcdefghi"));
	assertEqualInt(0, pathmatch("abc[d*", "abcdefghi"));
	assertEqualInt(1, pathmatch("abc[d*", "abc[defghi"));
	assertEqualInt(1, pathmatch("abc[d-f]", "abcd"));
	assertEqualInt(1, pathmatch("abc[d-f]", "abce"));
	assertEqualInt(1, pathmatch("abc[d-f]", "abcf"));
	assertEqualInt(0, pathmatch("abc[d-f]", "abcg"));
	assertEqualInt(1, pathmatch("abc[d-fh-k]", "abcd"));
	assertEqualInt(1, pathmatch("abc[d-fh-k]", "abce"));
	assertEqualInt(1, pathmatch("abc[d-fh-k]", "abcf"));
	assertEqualInt(0, pathmatch("abc[d-fh-k]", "abcg"));
	assertEqualInt(1, pathmatch("abc[d-fh-k]", "abch"));
	assertEqualInt(1, pathmatch("abc[d-fh-k]", "abci"));
	assertEqualInt(1, pathmatch("abc[d-fh-k]", "abcj"));
	assertEqualInt(1, pathmatch("abc[d-fh-k]", "abck"));
	assertEqualInt(0, pathmatch("abc[d-fh-k]", "abcl"));
	assertEqualInt(0, pathmatch("abc[d-fh-k]", "abc-"));
	assertEqualInt(0, pathmatch("abc[d-fh-]", "abcl"));
	assertEqualInt(1, pathmatch("abc[d-fh-]", "abch"));
	assertEqualInt(1, pathmatch("abc[d-fh-]", "abc-"));
	assertEqualInt(1, pathmatch("abc[d-fh-]", "abc-"));
	/* I assume: initial ']' is non-special. */
	assertEqualInt(1, pathmatch("abc[]]", "abc]"));
	assertEqualInt(1, pathmatch("abc[]d]", "abc]"));
	assertEqualInt(1, pathmatch("abc[]d]", "abcd"));
	assertEqualInt(1, pathmatch("abc[d]e]", "abcde]"));
	assertEqualInt(0, pathmatch("abc[d]e]", "abc]"));

	/* TODO: Implement leading '!' as negation character. */
}
