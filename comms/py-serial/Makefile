# $NetBSD: Makefile,v 1.6 2016/06/08 17:43:20 wiz Exp $

DISTNAME=		pyserial-2.7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		comms python
MASTER_SITES=		${MASTER_SITE_PYPI:=p/pyserial/}

MAINTAINER=		tsarna@NetBSD.org
HOMEPAGE=		http://pyserial.sourceforge.net/
COMMENT=		Python Serial Port Extension
LICENSE=		python-software-foundation

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

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
