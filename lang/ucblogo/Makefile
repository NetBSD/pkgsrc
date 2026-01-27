# $NetBSD: Makefile,v 1.48 2026/01/27 08:40:01 wiz Exp $

DISTNAME=	ucblogo-6.2.1
PKGREVISION=	16
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=jrincayc/}
GITHUB_PROJECT=	ucblogo-code
GITHUB_RELEASE=	version_${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.eecs.berkeley.edu/~bh/logo.html
COMMENT=	UCB (Berkeley) Logo interpreter
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=		c c++

GNU_CONFIGURE=		yes

# Enable object oriented Logo features
CONFIGURE_ARGS+=	--enable-objects

USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CFLAGS+=	-Wno-incompatible-pointer-types

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
