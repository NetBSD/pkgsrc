# $NetBSD: Makefile,v 1.14 2006/03/14 01:14:29 jlam Exp $
#

DISTNAME=	xscavenger-1.4.4
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://www.xdr.com/dash/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.xdr.com/dash/scavenger.html
COMMENT=	Loderunner clone with sound for X11

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_IMAKE=		yes
CONFIGURE_DIRS=		src
BUILD_DIRS=		${CONFIGURE_DIRS}
NO_INSTALL_MANPAGES=	yes
DEINSTALL_SRC=		${PKGDIR}/DEINSTALL
INSTALL_SRC=		# empty

CPPFLAGS+=	-DSOUNDDEV="\"${DEVOSSSOUND}\""

INSTALLATION_DIRS=	man/man6

.include "../../mk/oss.buildlink3.mk"

post-install:
	@${INSTALL_MAN} ${WRKSRC}/src/scavenger.6 ${PREFIX}/man/man6/
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scavenger
	@${INSTALL_MAN} ${WRKSRC}/DOC ${PREFIX}/share/doc/scavenger

.include "../../mk/bsd.pkg.mk"
