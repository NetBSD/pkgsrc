# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 23:04:00 markd Exp $

DISTNAME=		kdiff3-0.9.91
PKGREVISION=		14
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
SET_LIBDIR=		yes
CONFIGURE_ARGS+=	--without-arts

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
