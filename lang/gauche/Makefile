# $NetBSD: Makefile,v 1.18 2003/09/17 16:52:10 yyamano Exp $
#

DISTNAME=	Gauche-0.6.3
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation developed to be a handy script interpreter

# devel/boehm-gc cannot be used because Gauche requires PIC version
#DEPENDS+=	boehm-gc-[0-9]*:../../devel/boehm-gc
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
USE_BUILDLINK2=	yes
CONFIGURE_ARGS+=	--with-slib=${PREFIX}/share/slib
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ENV+=		AS="${CC} -x assembler-with-cpp -c"

_WITH_ICONV_LIB=	${BUILDLINK_LIBICONV_LDADD:M-l*:C/-l//}
LDFLAGS+=		${BUILDLINK_LIBICONV_LDADD}

USE_MAKEINFO=		YES
INFO_FILES=		gauche-refe.info gauche-refj.info

.include "../../mk/bsd.prefs.mk"
.if defined(GAUCHE_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte=${GAUCHE_MULTIBYTE}
.endif

.if ${OPSYS} == "Darwin"
.  include "../../devel/dlcompat/buildlink2.mk"
.endif
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

.if !empty(_WITH_ICONV_LIB)
CONFIGURE_ARGS+=	--with-iconv-lib=${_WITH_ICONV_LIB}
.else
BUILDLINK_TRANSFORM+=	S:-liconv:
.endif
