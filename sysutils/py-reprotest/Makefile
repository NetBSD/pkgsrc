# $NetBSD: Makefile,v 1.2 2022/11/09 22:51:19 wiz Exp $

DISTNAME=	reprotest-0.7.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reprotest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://salsa.debian.org/reproducible-builds/reprotest
COMMENT=	Build packages and check them for reproducibility
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-diffoscope>=226:../../sysutils/py-diffoscope
DEPENDS+=	${PYPKGPREFIX}-distro>=0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-rstr>=0:../../devel/py-rstr

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	reprotest/virt/autopkgtest-virt-chroot \
			reprotest/virt/autopkgtest-virt-lxc    \
			reprotest/virt/autopkgtest-virt-lxd    \
			reprotest/virt/autopkgtest-virt-null   \
			reprotest/virt/autopkgtest-virt-qemu   \
			reprotest/virt/autopkgtest-virt-schroot \
			reprotest/virt/autopkgtest-virt-ssh

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} reprotest reprotest-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
