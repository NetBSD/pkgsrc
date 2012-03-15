# $NetBSD: Makefile,v 1.5 2012/03/15 11:53:35 obache Exp $
#

DISTNAME=	Coherence-0.6.6.2
PKGNAME=	coherence-0.6.6.2
PKGREVISION=	1
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
