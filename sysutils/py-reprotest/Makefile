# $NetBSD: Makefile,v 1.4 2024/06/11 09:28:46 adam Exp $

DISTNAME=	reprotest-0.7.27
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reprotest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://salsa.debian.org/reproducible-builds/reprotest
COMMENT=	Build packages and check them for reproducibility
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-distro-[0-9]*:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-rstr-[0-9]*:../../devel/py-rstr
# compare
DEPENDS+=	${PYPKGPREFIX}-diffoscope>=112:../../sysutils/py-diffoscope
TEST_DEPENDS+=	dpkg-[0-9]*:../../misc/dpkg

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-chroot
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-lxc
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-lxd
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-null
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-qemu
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-schroot
REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-ssh

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} reprotest reprotest-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
