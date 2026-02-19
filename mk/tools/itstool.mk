# $NetBSD: itstool.mk,v 1.3 2026/02/19 14:31:11 wiz Exp $

.if !empty(USE_TOOLS:C/:.*//:Mitstool)
.  if !empty(USE_TOOLS:Mitstool\:test)
_TOOLS_DEPMETHOD.itstool=      TEST_DEPENDS
.  else
_TOOLS_DEPMETHOD.itstool=      TOOL_DEPENDS
.  endif
.  if empty(${_TOOLS_DEPMETHOD.itstool}:M${TOOLS_DEPENDS.itstool})
${_TOOLS_DEPMETHOD.itstool}+=	itstool-[0-9]*:../../textproc/itstool
.  endif
TOOLS_CREATE+=		itstool
TOOLS_PATH.itstool=	${TOOLBASE}/bin/itstool
.else
#
# If a package doesn't explicitly say it uses itstool, then create a "broken"
# itstool in the tools directory.
#
TOOLS_FAIL+=		itstool
TOOLS_PATH.itstool=	${TOOLS_CMD.itstool}
.endif

CONFIGURE_ENV+=		ITSTOOL=${TOOLS_CMD.itstool:Q}
MAKE_ENV+=		ITSTOOL=${TOOLS_CMD.itstool:Q}
