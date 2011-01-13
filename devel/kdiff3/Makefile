# $NetBSD: Makefile,v 1.12 2011/01/13 13:37:24 wiz Exp $

DISTNAME=		kdiff3-0.9.91
PKGREVISION=		9
CATEGORIES=		devel kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kdiff3/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kdiff3.sourceforge.net/
COMMENT=		File and directory diff and merge tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		msgfmt
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-arts

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
