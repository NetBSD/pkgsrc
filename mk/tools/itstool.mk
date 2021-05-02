# $NetBSD: itstool.mk,v 1.1 2021/05/02 10:24:50 nia Exp $

.if !empty(USE_TOOLS:Mitstool)
TOOLS_CREATE+=		itstool
TOOLS_DEPENDS.itstool?=	itstool-[0-9]*:../../textproc/itstool
TOOLS_PATH.itstool=	${PREFIX}/bin/itstool
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
