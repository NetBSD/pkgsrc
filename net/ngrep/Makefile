# $NetBSD: Makefile,v 1.9 2002/10/10 13:29:37 wiz Exp $
#

DISTNAME=	ngrep-1.39
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngrep/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://ngrep.sourceforge.net/
COMMENT=	network grep

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pcre
# ngrep's configure use --includedir/$includedir in a weird way!
CONFIGURE_ARGS+=--includedir=${BUILDLINK_PREFIX.libpcap}/include
WRKSRC=		${WRKDIR}/ngrep
ALL_TARGET=	ngrep

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
do-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX}
.endif

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
