# $NetBSD: Makefile,v 1.4 2003/05/02 11:55:51 wiz Exp $
#

DISTNAME=	kanjipad-1.2.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.gtk.org/pub/users/otaylor/kanjipad/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gtk.org/~otaylor/kanjipad/index.html
COMMENT=	Japanese handwriting recognition with GTK interface

USE_PERL5=	build

USE_BUILDLINK2=		YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kanjipad
	${INSTALL_PROGRAM} ${WRKSRC}/kanjipad ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/kpengine ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jdata.dat ${PREFIX}/share/kanjipad

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
