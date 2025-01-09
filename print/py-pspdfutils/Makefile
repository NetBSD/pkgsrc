# $NetBSD: Makefile,v 1.21 2025/01/09 08:56:36 wiz Exp $

DISTNAME=	psutils-3.3.8
# renamed from pspdfutils to psutils in 3.3.7
# TODO: follow suit
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/ps/pspdf/}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/psutils
COMMENT=	Manipulate PDF and PostScript documents
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-argparse-manpage-[0-9]*:../../devel/py-argparse-manpage
DEPENDS+=	${PYPKGPREFIX}-puremagic>=1.26:../../sysutils/py-puremagic
DEPENDS+=	${PYPKGPREFIX}-pdf>=4.3.0:../../textproc/py-pdf
TEST_DEPENDS+=	${PYPKGPREFIX}-test-datafiles>=0:../../devel/py-test-datafiles
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath
TEST_DEPENDS+=	${PYPKGPREFIX}-wand>=0:../../graphics/py-wand

CONFLICTS+=	psutils<3

INSTALLATION_DIRS+=	${PKGMANDIR}

PYTHON_SELF_CONFLICT=		yes

.include "../../mk/bsd.prefs.mk"
post-install:
.if ${PKGMANDIR} != "share/man"
	cd ${DESTDIR}${PREFIX}/share/man && ${MV} * ${DESTDIR}${PREFIX}/${PKGMANDIR}
.endif
# https://github.com/rrthomas/psutils/issues/75
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/psutils-${PKGVERSION_NOREV}.dist-info/.bak.*

.include "../../print/libpaper/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
