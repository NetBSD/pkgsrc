# $NetBSD: Makefile,v 1.6 2019/09/20 11:36:28 adam Exp $

.include "../../devel/libevent/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/libevent/libevent-rpcgen/:S/-stable//}
COMMENT=	Python libevent rpcgen script

NO_BUILD=		yes
INSTALLATION_DIRS+=	bin

PYTHON_SELF_CONFLICT=	yes
REPLACE_PYTHON=		event_rpcgen.py

do-configure:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/event_rpcgen.py ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
