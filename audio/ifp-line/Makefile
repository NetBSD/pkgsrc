# $NetBSD: Makefile,v 1.10 2010/01/30 18:13:35 joerg Exp $

DISTNAME=		ifp-line-0.2.4.4
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ifp-driver/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://ifp-driver.sourceforge.net/
COMMENT=		Command-line interface to iRiver MP3 players

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
