# $NetBSD: Makefile,v 1.8 2017/04/22 21:03:09 adam Exp $
#

DISTNAME=	grantlee-5.1.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://downloads.grantlee.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gitorious.org/grantlee/pages/Home
COMMENT=	String template engine in QT5 based on Django template system
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=  c c++
USE_CMAKE=      yes

# Unbreak nested templates https://github.com/steveire/grantlee/issues/27
post-patch:
	cd ${WRKSRC}; find . -type f -name '*.h' -exec sed -e 's|>>|> >|g' -i {} \;

.include "../../x11/qt5-qtscript/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
