# $NetBSD: gdbus-codegen.mk,v 1.1 2021/05/02 11:06:13 nia Exp $

.if !empty(USE_TOOLS:Mgdbus-codegen)
TOOLS_CREATE+=			gdbus-codegen
TOOLS_DEPENDS.gdbus-codegen?=	gdbus-codegen-[0-9]*:../../textproc/gdbus-codegen
TOOLS_PATH.gdbus-codegen=	${PREFIX}/bin/gdbus-codegen
.else
#
# If a package doesn't explicitly say it uses gdbus-codegen, then create a "broken"
# gdbus-codegen in the tools directory.
#
TOOLS_FAIL+=			gdbus-codegen
TOOLS_PATH.gdbus-codegen=	${TOOLS_CMD.gdbus-codegen}
.endif

CONFIGURE_ENV+=		GDBUS_CODEGEN=${TOOLS_CMD.gdbus-codegen:Q}
MAKE_ENV+=		GDBUS_CODEGEN=${TOOLS_CMD.gdbus-codegen:Q}
