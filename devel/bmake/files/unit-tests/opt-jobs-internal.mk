# $NetBSD: opt-jobs-internal.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the (intentionally undocumented) -J command line option.
#
# Only test the error handling here, the happy path is covered in other tests
# as a side effect.

# expect: make: internal error -- J option malformed (garbage)
.MAKEFLAGS: -Jgarbage
