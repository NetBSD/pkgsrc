# $NetBSD: Makefile,v 1.2 2009/07/13 14:50:40 joerg Exp $
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

DEPENDS+= ${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
