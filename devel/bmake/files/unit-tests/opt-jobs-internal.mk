# $NetBSD: opt-jobs-internal.mk,v 1.1 2024/07/15 09:10:24 jperkin Exp $
#
# Tests for the (intentionally undocumented) -J command line option.
#
# Only test the error handling here, the happy path is covered in other tests
# as a side effect.

# expect: make: internal error -- J option malformed (garbage)
.MAKEFLAGS: -Jgarbage
