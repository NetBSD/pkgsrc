# $NetBSD: hacks.mk,v 1.1 2021/05/07 13:01:58 rin Exp $

.if !defined(GETTEXT_TOOLS_HACKS_MK)
GETTEXT_TOOLS_HACKS_MK=	defined

.include "../../mk/compiler.mk"

# GCC 10 and 9 miscompile this for alpha, which results in SIGSEGV for
# ``env LANG=en_US.UTF-8 /usr/pkg/bin/xgettext --version''.
.if ${MACHINE_ARCH} == "alpha" && \
    (!empty(CC_VERSION:Mgcc-10.*) || !empty(CC_VERSION:Mgcc-9.*))
PKG_HACKS+=	optimisation
CFLAGS+=	-O0
CXXFLAGS+=	-O0
.endif

.endif
