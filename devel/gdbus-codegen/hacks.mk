# $NetBSD: hacks.mk,v 1.1 2012/11/13 21:23:07 adam Exp $

.if !defined(GDBUS_CODEGEN_HACKS_MK)
GDBUS_CODEGEN_HACKS_MK=	# defined

.if ${OPSYS} == "Darwin"
CHECK_BUILTIN.libiconv:=	yes
. include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.libiconv:=	no
PKG_HACKS+=		darwin-iconv
SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_MESSAGE.iconv=	Changing libiconv_open to iconv_open.
SUBST_FILES.iconv=	configure
SUBST_SED.iconv=	-e 's,libiconv_open,iconv_open,g'
.endif

.endif
