# $NetBSD: Makefile,v 1.14 2004/01/30 14:36:09 adam Exp $
#

DISTNAME=	ngrep-1.41
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngrep/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://ngrep.sourceforge.net/
COMMENT=	Network grep

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pcre
# ngrep's configure use --includedir/$includedir in a weird way!
CONFIGURE_ARGS+=	--includedir=${BUILDLINK_PREFIX.libpcap}/include
ALL_TARGET=		ngrep

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
do-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX}
.endif

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
