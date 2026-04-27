# $NetBSD: Makefile,v 1.1 2026/04/27 10:23:50 adam Exp $

DISTNAME=	qemu_qmp-0.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	emulators python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qemu.qmp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qemu.org/
COMMENT=	QEMU Monitor Protocol library
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
# tui
DEPENDS+=	${PYPKGPREFIX}-urwid>=2.1.2:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-urwid_readline>=0.13:../../devel/py-urwid_readline
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.9.0:../../textproc/py-pygments

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	qmp-shell qmp-shell-wrap qmp-tui

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
