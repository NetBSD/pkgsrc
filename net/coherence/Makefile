# $NetBSD: Makefile,v 1.4 2010/05/20 21:22:51 drochner Exp $
#

DISTNAME=	Coherence-0.6.6.2
PKGNAME=	coherence-0.6.6.2
CATEGORIES=	net
MASTER_SITES=	http://coherence.beebits.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coherence.beebits.net/
COMMENT=	Media server framework

USE_LANGUAGES=	# none
PKG_DESTDIR_SUPPORT= user-destdir

DEPENDS+= ${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
