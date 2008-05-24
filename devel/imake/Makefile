# $NetBSD: Makefile,v 1.6 2008/05/24 21:45:20 tnn Exp $
#

DISTNAME=		imake-1.0.2
PKGREVISION=		2
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Imake and other utilities from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config makedepend:run perl:run

DEPENDS+=		xorg-cf-files>=1.0.2nb1:../../x11/xorg-cf-files

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

REPLACE_PERL+=		mkhtmlindex.pl

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
