# $NetBSD: Makefile,v 1.66 2012/10/02 17:10:55 tron Exp $

DISTNAME=		kile-2.1.1
PKGREVISION=		5
CATEGORIES=		editors kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kile/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://kile.sourceforge.net/
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+= automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=		perl msgfmt
USE_LANGUAGES=		c c++

REPLACE_PERL=		kile1.6_upd.pl \
			kile1.7_upd.pl \
			kile1.9_upd.pl \
			kile1.9-1_upd.pl \
			kile2.0-1_upd.pl \
			kile2.0-2_upd.pl \
			kile2.0-3_upd.pl \
			kile2.0-4_upd.pl \
			kile2.0-5_upd.pl

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
