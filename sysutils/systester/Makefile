# $NetBSD: Makefile,v 1.14 2023/10/24 22:11:15 wiz Exp $

DISTNAME=	systester-1.5.1
PKGREVISION=	9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=systester/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://systester.sourceforge.net/
COMMENT=	Test system stability and performance by calculating Pi
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}

# ftime()
LDFLAGS.NetBSD+=	-lcompat

.include "../../devel/gmp/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
