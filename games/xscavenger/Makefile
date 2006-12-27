# $NetBSD: Makefile,v 1.17 2006/12/27 13:37:37 joerg Exp $
#

DISTNAME=	xscavenger-1.4.4
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	http://www.xdr.com/dash/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xdr.com/dash/scavenger.html
COMMENT=	Loderunner clone with sound for X11

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_IMAKE=		yes
CONFIGURE_DIRS=		src
BUILD_DIRS=		${CONFIGURE_DIRS}
NO_INSTALL_MANPAGES=	yes

CPPFLAGS+=	-DSOUNDDEV="\"${DEVOSSSOUND}\""

INSTALLATION_DIRS=	man/man6

.include "../../mk/oss.buildlink3.mk"

post-install:
	@${INSTALL_MAN} ${WRKSRC}/src/scavenger.6 ${PREFIX}/man/man6/
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scavenger
	@${INSTALL_MAN} ${WRKSRC}/DOC ${PREFIX}/share/doc/scavenger

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
