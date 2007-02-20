# $NetBSD: Makefile,v 1.1.1.1 2007/02/20 22:58:34 xtraeme Exp $
#

DISTNAME=	cryptofs-0.6.0
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	http://reboot.animeirc.de/cryptofs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://reboot.animeirc.de/cryptofs/
COMMENT=	FUSE encrypted filesystem

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	share/doc/${PKGBASE} share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/cryptofs.conf \
		${PREFIX}/share/examples/${PKGBASE}

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
