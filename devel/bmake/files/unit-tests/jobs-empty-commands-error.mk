# $NetBSD: jobs-empty-commands-error.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# In jobs mode, the shell commands for creating a target are written to a
# temporary file first, which is then run by the shell.  In chains of
# dependencies, these files would end up empty.  Since job.c 1.399 from
# 2021-01-29, these empty files are no longer created.
#
# After 2021-01-29, before job.c 1.435 2021-06-16, targets that could not be
# made led to longer error messages than necessary.

.MAKEFLAGS: -j1

all: existing-target

existing-target:
	: 'Making $@ out of nothing.'

all: nonexistent-target
	: 'Not reached'
