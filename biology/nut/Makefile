# $NetBSD: Makefile,v 1.24 2008/01/19 09:16:19 wiz Exp $

DISTNAME=	nut-10.18
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	# ${MASTER_SITE_SOURCEFORGE:=nut/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nut.sourceforge.net/
COMMENT=	Record what you eat and analyze your meals

BUILD_TARGET=	nut
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nut ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/nut
	${INSTALL_DATA} ${WRKSRC}/raw.data/* ${PREFIX}/share/nut
	${INSTALL_MAN} ${WRKSRC}/nut.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
