# $NetBSD: Makefile,v 1.4 2013/11/08 15:33:32 riz Exp $
#

DISTNAME=		buildbot-slave-0.8.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=		buildbot_slave-0.8.8
CATEGORIES=		devel net python
MASTER_SITES=		http://buildbot.googlecode.com/files/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://buildbot.net/
COMMENT=		Buildbot slave
LICENSE=		gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
