# $NetBSD: Makefile,v 1.1.1.1 2001/05/31 09:56:58 minoura Exp $
#

DISTNAME=	Gauche-0.3.13
CATEGORIES=	lang
MASTER_SITES=	http://prdownloads.sourceforge.net/gauche/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minoura@netbsd.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation developed to be a handy script interpreter

# devel/boehm-gc cannot be used because Gauche requires PIC version
#DEPENDS+=	boehm-gc-*:../../devel/boehm-gc
DEPENDS+=	slib-*:../../devel/slib
# XXX: On newer SunOS/Linux we have to use their native iconv(3)...?
DEPENDS+=	libiconv-*:../../converters/libiconv

NOT_FOR_PLATFORM= *-*-alpha *-*-sparc64	# Gauche is not LP64 safe for now

WRKSRC=		${WRKDIR}/Gauche
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-slib=${PREFIX}/share/slib
CONFIGURE_ARGS+=	--with-iconv=${PREFIX}/include
CFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"
.if defined(GAUCHE_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte=${GAUCHE_MULTIBYTE}
.endif

.include "../../mk/bsd.pkg.mk"
