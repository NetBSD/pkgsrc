# $NetBSD: Makefile,v 1.23 2004/08/08 07:05:38 minoura Exp $
#

DISTNAME=	Gauche-0.8.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation aimed to be a handy tool for daily works

DEPENDS+=	slib-[0-9]*:../../devel/slib

# Due to GC dynamic loading support, this package runs on limited platforms
# Plus, it is not LP64-safe
ONLY_FOR_PLATFORM= NetBSD-*-i386 NetBSD-*-sparc NetBSD-*-mipsel NetBSD-*-powerpc
ONLY_FOR_PLATFORM+= Linux-*-* SunOS-*-* Darwin-*-*
.include "../../mk/bsd.prefs.mk"
.if (${MACHINE_ARCH} == "i386" && ${OPSYS} == "NetBSD")
.  if ${OBJECT_FMT} != "ELF"
BROKEN=Test required on NetBSD/i386 a.out
.  endif
.endif

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
CONFIGURE_ARGS+=	--with-slib=${PREFIX}/share/slib
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--enable-threads=none	# must match w/ boehm-gc
CONFIGURE_ENV+=		AS="${CC} -x assembler-with-cpp -c"

_WITH_ICONV_LIB=	${BUILDLINK_LIBICONV_LDADD:M-l*:C/-l//}
LDFLAGS+=		${BUILDLINK_LIBICONV_LDADD}

USE_MAKEINFO=		YES
INFO_FILES=		gauche-refe.info gauche-refj.info

.include "../../mk/bsd.prefs.mk"
.if defined(GAUCHE_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte=${GAUCHE_MULTIBYTE}
.endif

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/dlcompat/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if !empty(_WITH_ICONV_LIB)
CONFIGURE_ARGS+=	--with-iconv-lib=${_WITH_ICONV_LIB}
.else
BUILDLINK_TRANSFORM+=	S:-liconv:
.endif
