# $NetBSD: Makefile,v 1.13 2004/01/20 12:22:20 agc Exp $
#

DISTNAME=	ngrep-1.39
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngrep/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://ngrep.sourceforge.net/
COMMENT=	Network grep

WRKSRC=		${WRKDIR}/ngrep
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pcre
# ngrep's configure use --includedir/$includedir in a weird way!
CONFIGURE_ARGS+=--includedir=${BUILDLINK_PREFIX.libpcap}/include
ALL_TARGET=	ngrep

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
do-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX}
.endif

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
