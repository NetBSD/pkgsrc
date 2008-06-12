# $NetBSD: Makefile,v 1.12 2008/06/12 02:14:32 joerg Exp $

DISTNAME=	piddle-1.0.15
PKGREVISION=	2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=piddle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://piddle.sourceforge.net/
COMMENT=	Python Plug In Drawing, Does Little Else

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	# defined

NO_CONFIGURE=	YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
