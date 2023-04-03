# $NetBSD: Makefile,v 1.46 2023/04/03 20:20:48 nros Exp $
#

DISTNAME=	grantlee-5.2.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	16
CATEGORIES=	devel
MASTER_SITES=	http://downloads.grantlee.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/steveire/grantlee
COMMENT=	String template engine in QT5 based on Django template system
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../x11/qt5-qtscript/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
