# $NetBSD: Makefile,v 1.30 2020/06/07 01:46:52 markd Exp $
#

DISTNAME=	grantlee-5.2.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}
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
