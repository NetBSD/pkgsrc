# $NetBSD: Makefile,v 1.7 2017/07/31 13:11:27 adam Exp $

DISTNAME=	pyserial-3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyserial/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	https://github.com/pyserial/pyserial
COMMENT=	Python Serial Port Extension
LICENSE=	modified-bsd

CONFLICTS+=		${PYPKGPREFIX}-pyserial-[0-9]*

USE_LANGUAGES=		# none

REPLACE_PYTHON+=	serial/__init__.py
REPLACE_PYTHON+=	serial/rfc2217.py
REPLACE_PYTHON+=	serial/serialcli.py
REPLACE_PYTHON+=	serial/serialjava.py
REPLACE_PYTHON+=	serial/serialposix.py
REPLACE_PYTHON+=	serial/serialutil.py
REPLACE_PYTHON+=	serial/serialwin32.py
REPLACE_PYTHON+=	serial/sermsdos.py
REPLACE_PYTHON+=	serial/tools/__init__.py
REPLACE_PYTHON+=	serial/tools/list_ports.py
REPLACE_PYTHON+=	serial/tools/list_ports_linux.py
REPLACE_PYTHON+=	serial/tools/list_ports_osx.py
REPLACE_PYTHON+=	serial/tools/list_ports_posix.py
REPLACE_PYTHON+=	serial/tools/list_ports_windows.py
REPLACE_PYTHON+=	serial/tools/miniterm.py
REPLACE_PYTHON+=	serial/urlhandler/__init__.py
REPLACE_PYTHON+=	serial/urlhandler/protocol_hwgrep.py
REPLACE_PYTHON+=	serial/urlhandler/protocol_loop.py
REPLACE_PYTHON+=	serial/urlhandler/protocol_rfc2217.py
REPLACE_PYTHON+=	serial/urlhandler/protocol_socket.py
REPLACE_PYTHON+=	serial/win32.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} miniterm.py miniterm${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
