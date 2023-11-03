# $NetBSD: Makefile,v 1.50 2023/11/03 21:14:53 wiz Exp $

DISTNAME=	gnome-mastermind-0.4.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fargiolas/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fargiolas/gnome-mastermind
COMMENT=	Mastermind (the game)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake itstool intltool pkg-config # msgfmt

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
