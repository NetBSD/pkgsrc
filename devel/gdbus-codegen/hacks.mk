# $NetBSD: hacks.mk,v 1.3 2013/08/17 04:59:07 obache Exp $

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

#
# GLib2>=2.36 depends on builtin functions which enabled with i486 and
# later with GCC.
#
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5]*-i386)
GNU_ARCH.i386=		i486
CFLAGS+=		-march=i486
.endif

.endif
