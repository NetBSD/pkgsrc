# $NetBSD: Makefile,v 1.33 2022/08/11 05:08:55 gutteridge Exp $

GITHUB_PROJECT=	ucblogo-code
GITHUB_RELEASE=	version_${PKGVERSION_NOREV}
DISTNAME=	ucblogo-6.2.1
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=jrincayc/}

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

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
