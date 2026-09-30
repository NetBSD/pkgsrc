# $NetBSD: Makefile,v 1.9 2026/09/30 09:28:02 adam Exp $

DISTNAME=	reprotest-0.7.33
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reprotest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://salsa.debian.org/reproducible-builds/reprotest
COMMENT=	Build packages and check them for reproducibility
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-distro>=0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-rstr>=0:../../devel/py-rstr
# compare
DEPENDS+=	${PYPKGPREFIX}-diffoscope>=112:../../sysutils/py-diffoscope
TEST_DEPENDS+=	dpkg>=0:../../misc/dpkg

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	reprotest

REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-chroot
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-lxc
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-lxd
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-null
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-qemu
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-schroot
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-ssh

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
