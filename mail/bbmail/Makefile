# $NetBSD: Makefile,v 1.16 2007/02/15 14:46:27 joerg Exp $
#

DISTNAME=	bbmail-0.8.3
PKGREVISION=	1
CATEGORIES=	mail x11
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	Mailbox monitor (not only) for the blackbox windowmanager

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbmail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bbmail.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/bbtools/
	${INSTALL_DATA} ${WRKSRC}/data/bbmail.bb ${PREFIX}/share/bbtools/

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
