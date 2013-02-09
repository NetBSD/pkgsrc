# $NetBSD: Makefile,v 1.7 2013/02/09 22:11:35 ryoon Exp $

DISTNAME=		kdiff3-0.9.91
PKGREVISION=		19
CATEGORIES=		devel kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kdiff3/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kdiff3.sourceforge.net/
COMMENT=		File and directory diff and merge tool

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
