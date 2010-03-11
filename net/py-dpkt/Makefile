# $NetBSD: Makefile,v 1.1.1.1 2010/03/11 11:31:19 pettai Exp $
#

DISTNAME=	dpkt-1.6
PKGNAME=	${PYPKGPREFIX}-dpkt-1.6
CATEGORIES=	net python
MASTER_SITES=	http://dpkt.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/dpkt/
COMMENT=	Python packet creation / parsing library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
