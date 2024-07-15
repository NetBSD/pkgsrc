# $NetBSD: depsrc-end.mk,v 1.1 2024/07/15 09:10:13 jperkin Exp $
#
# Demonstrate an edge case in which .BEGIN depends on .END, which sounds a bit
# paradox but works since these special nodes are not in the dependency
# hierarchy where the cycles are detected.

.BEGIN:
	: 'Making ${.TARGET}.'
.END:
	: 'Making ${.TARGET}.'
all:
	: 'Making ${.TARGET}.'

.BEGIN: .END
