# $NetBSD: Makefile,v 1.18 2024/10/14 06:45:56 wiz Exp $

DISTNAME=	pspdfutils-3.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pspdfutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/psutils
COMMENT=	Manipulate PDF and PostScript documents
LICENSE=	gnu-gpl-v3

CONFLICTS+=	psutils<3

TOOL_DEPENDS+=	${PYPKGPREFIX}-argparse-manpage-[0-9]*:../../devel/py-argparse-manpage
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-puremagic>=1.26:../../sysutils/py-puremagic
DEPENDS+=	${PYPKGPREFIX}-pdf>=4.3.0:../../textproc/py-pdf
TEST_DEPENDS+=	${PYPKGPREFIX}-test-datafiles>=0:../../devel/py-test-datafiles
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath
TEST_DEPENDS+=	${PYPKGPREFIX}-wand>=0:../../graphics/py-wand

INSTALLATION_DIRS+=	${PKGMANDIR}

PYTHON_SELF_CONFLICT=		yes

.include "../../mk/bsd.prefs.mk"
post-install:
.if ${PKGMANDIR} != "share/man"
	cd ${DESTDIR}${PREFIX}/share/man && ${MV} * ${DESTDIR}${PREFIX}/${PKGMANDIR}
.endif

.include "../../print/libpaper/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
