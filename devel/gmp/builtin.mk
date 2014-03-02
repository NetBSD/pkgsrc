# $NetBSD: builtin.mk,v 1.4 2014/03/02 08:00:00 obache Exp $

BUILTIN_PKG:=	gmp

PKGCONFIG_FILE.gmp=	/usr/include/gmp.h /usr/include/gmp/gmp.h
PKGCONFIG_BASE.gmp=	/usr

BUILTIN_VERSION_SCRIPT.gmp= ${AWK} \
	'/\#define[ \t]*__GNU_MP_VERSION[ \t]/ { major = $$3; } \
	/\#define[ \t]*__GNU_MP_VERSION_MINOR[ \t]/ { minor = $$3; } \
	/\#define[ \t]*__GNU_MP_VERSION_PATCHLEVEL[ \t]/ { patch = $$3; } \
	END { if (major!="" && minor!="" && patch!="") \
	print major "." minor "." patch; else print ""; }'

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

CHECK_BUILTIN.gmp?=	no
.if !empty(CHECK_BUILTIN.gmp:M[Nn][Oo])
.  if !empty(USE_BUILTIN.gmp:M[Yy][Ee][Ss])
GMP_INCLUDE=		${FIND_FILES_gmp:S/\/gmp.h//}
CONFIGURE_ARGS+=	--with-gmp-include=${GMP_INCLUDE}
CPPFLAGS+=		-I${GMP_INCLUDE}
CFLAGS+=		-I${GMP_INCLUDE}
.  endif
.endif # CHECK_BUILTIN.gmp
