# $NetBSD: Makefile,v 1.23 2020/03/20 11:58:04 nia Exp $
#

DISTNAME=	labrea-2.5-stable-1
PKGNAME=	LaBrea-2.5
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=labrea/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labrea.sourceforge.net/labrea-info.html
COMMENT=	Builds tarpits/honeypots for scanners

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	YES

CONF_FILES=	${PREFIX}/share/examples/LaBrea/labrea.conf \
		${PKG_SYSCONFDIR}/labrea.conf

INSTALLATION_DIRS=	share/doc/LaBrea share/examples/LaBrea

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/LaBrea
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/LaBrea
	${INSTALL_DATA} ${WRKSRC}/misc/labrea.conf \
		${DESTDIR}${PREFIX}/share/examples/LaBrea

.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
