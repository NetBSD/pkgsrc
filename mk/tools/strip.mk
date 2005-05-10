# $NetBSD: strip.mk,v 1.1 2005/05/10 19:52:30 jlam Exp $
#
# Depending on whether _INSTALL_UNSTRIPPED is defined, we cause
# ${TOOLS_DIR}/bin/strip to be either the correct strip tool or a no-op.
#
.if defined(_INSTALL_UNSTRIPPED) || !defined(TOOLS_PLATFORM.strip)
TOOLS_NOOP+=		strip
.else
TOOLS_CREATE+=		strip
TOOLS_REAL_CMD.strip=	${TOOLS_PLATFORM.strip}
.endif

# Make ${STRIP} call "strip" through the PATH, which should find the one
# under ${TOOLS_DIR}.
#
STRIP?=		strip
