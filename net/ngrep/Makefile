# $NetBSD: Makefile,v 1.8 2001/09/14 23:05:42 wiz Exp $
#

DISTNAME=	ngrep-1.39
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngrep/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://ngrep.sourceforge.net/
COMMENT=	network grep

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pcre
# ngrep's configure use --includedir/$includedir in a weird way!
CONFIGURE_ARGS+=--includedir=${BUILDLINK_DIR}/include
WRKSRC=		${WRKDIR}/ngrep
ALL_TARGET=	ngrep

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
do-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX}
.endif

.include "../../net/libpcap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
