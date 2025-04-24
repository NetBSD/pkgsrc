# $NetBSD: Makefile,v 1.59 2025/04/24 14:13:56 wiz Exp $

DISTNAME=	gnome-mastermind-0.4.0
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fargiolas/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fargiolas/gnome-mastermind
COMMENT=	Mastermind (the game)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake itstool intltool msgfmt pkg-config

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
