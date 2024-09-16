# $NetBSD: Makefile,v 1.5 2024/09/16 08:29:06 adam Exp $

DISTNAME=	reprotest-0.7.28
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
