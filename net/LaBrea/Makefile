# $NetBSD: Makefile,v 1.18 2006/03/04 21:30:16 jlam Exp $
#

DISTNAME=	labrea-2.5-stable-1
PKGNAME=	LaBrea-2.5
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=labrea/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labrea.sourceforge.net/labrea-info.html
COMMENT=	Builds tarpits/honeypots for scanners

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	YES

CONF_FILES=	${PREFIX}/share/examples/LaBrea/labrea.conf \
		${PKG_SYSCONFDIR}/labrea.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/LaBrea
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/LaBrea
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/LaBrea
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/LaBrea
	${INSTALL_DATA} ${WRKSRC}/misc/labrea.conf \
		${PREFIX}/share/examples/LaBrea

.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
