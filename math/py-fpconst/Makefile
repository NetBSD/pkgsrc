# $NetBSD: Makefile,v 1.7 2008/09/02 02:59:35 obache Exp $
#

DISTNAME=	fpconst-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	# ${MASTER_SITE_SOURCEFORGE:=rsoap/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://research.warnes.net/projects/RStatServer/fpconst/
COMMENT=	IEEE 754 floating point special handling for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
