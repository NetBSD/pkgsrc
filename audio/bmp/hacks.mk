# $NetBSD: hacks.mk,v 1.1 2006/08/07 11:21:45 wiz Exp $

.include "../../mk/compiler.mk"

# gcc 4.x generates code that produces background noise during playback.
# Disabling optimizations when using this compiler solves the problem.
.if !empty(CC_VERSION:Mgcc-4*)
CFLAGS+=		-O0
CXXFLAGS+=		-O0
.endif
