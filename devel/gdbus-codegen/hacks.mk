# $NetBSD: hacks.mk,v 1.2 2013/03/18 14:01:24 jperkin Exp $

.if !defined(GDBUS_CODEGEN_HACKS_MK)
GDBUS_CODEGEN_HACKS_MK=	# defined

.if ${OPSYS} == "Darwin"
CHECK_BUILTIN.libiconv:=	yes
.  include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.libiconv:=	no
.  if !empty(USE_BUILTIN.iconv:M[Yy][Ee][Ss])
PKG_HACKS+=		darwin-iconv
SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_MESSAGE.iconv=	Changing libiconv_open to iconv_open.
SUBST_FILES.iconv=	configure
SUBST_SED.iconv=	-e 's,libiconv_open,iconv_open,g'
.  endif
.endif

.endif
