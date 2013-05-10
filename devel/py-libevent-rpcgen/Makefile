# $NetBSD: Makefile,v 1.3 2013/05/10 01:29:59 riastradh Exp $

.include "../../devel/libevent/Makefile.common"

PKGNAME=	py-libevent-rpcgen-${LIBEVENT_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libevent.org/
COMMENT=	Python libevent rpcgen script
LICENSE=	modified-bsd

REPLACE_PYTHON=		event_rpcgen.py

do-configure:
do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/event_rpcgen.py ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
