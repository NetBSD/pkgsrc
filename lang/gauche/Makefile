# $NetBSD: Makefile,v 1.26 2004/10/03 00:15:00 tv Exp $
#

DISTNAME=	Gauche-0.8.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation aimed to be a handy tool for daily works

DEPENDS+=	slib-[0-9]*:../../devel/slib

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
BUILDLINK_TRANSFORM+=	rm:-liconv
.endif
