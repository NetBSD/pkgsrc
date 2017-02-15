# $NetBSD: Makefile,v 1.5 2017/02/15 17:34:37 adam Exp $

.include "../../devel/libevent/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/libevent/libevent-rpcgen/:S/-stable//}
COMMENT=	Python libevent rpcgen script

NO_BUILD=		yes
INSTALLATION_DIRS+=	bin

REPLACE_PYTHON=		event_rpcgen.py

PYTHON_VERSIONS_ACCEPTED=	27

do-configure:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/event_rpcgen.py ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
