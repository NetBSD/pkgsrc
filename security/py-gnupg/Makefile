# $NetBSD: Makefile,v 1.16 2011/10/29 06:40:25 obache Exp $

DISTNAME=	GnuPGInterface-0.3.2
PKGNAME=	${PYPKGPREFIX}-gnupg-0.3.2
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=py-gnupg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://py-gnupg.sourceforge.net/
COMMENT=	Python module for GnuPG interface
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	gnupg>=1.0.0:../../security/gnupg

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
