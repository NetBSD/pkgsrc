# $NetBSD: Makefile,v 1.1.1.1 2009/07/08 17:20:50 drochner Exp $
#

DISTNAME=	Coherence-0.6.4
PKGNAME=	coherence-0.6.4
CATEGORIES=	net
MASTER_SITES=	http://coherence.beebits.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coherence.beebits.net/
COMMENT=	Media server framework

USE_LANGUAGES=	# none
PKG_DESTDIR_SUPPORT= user-destdir

DEPENDS+= ${PYPKGPREFIX}-twisted:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
