# $NetBSD: Makefile,v 1.7 2004/04/18 19:37:14 wiz Exp $
#

DISTNAME=	kanjipad-1.2.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.gtk.org/pub/users/otaylor/kanjipad/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gtk.org/~otaylor/kanjipad/index.html
COMMENT=	Japanese handwriting recognition with GTK interface

USE_PERL5=	build

USE_BUILDLINK3=		YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kanjipad
	${INSTALL_PROGRAM} ${WRKSRC}/kanjipad ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/kpengine ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jdata.dat ${PREFIX}/share/kanjipad

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
