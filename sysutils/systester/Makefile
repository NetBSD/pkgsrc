# $NetBSD: Makefile,v 1.1 2014/08/09 15:51:22 wiz Exp $

DISTNAME=	systester-1.5.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=systester/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://systester.sourceforge.net/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
# ftime()
MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}
LDFLAGS+=	-lcompat

.include "../../devel/gmp/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
