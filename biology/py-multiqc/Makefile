# $NetBSD: Makefile,v 1.7 2024/11/22 22:02:41 wiz Exp $

DISTNAME=	multiqc-1.25.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=m/multiqc/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/multiqc
COMMENT=	Aggregate bioinformatics analysis reports across samples and tools
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
# Use either py-kaleido (not in ports yet) or py-orca + py-psutil
# kaleido dep choreographer only works with chrome as of 2024-11-24
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-orca-[0-9]*:../../devel/py-orca
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.7.0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-typeguard-[0-9]*:../../devel/py-typeguard
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-rich-click-[0-9]*:../../devel/py-rich-click
DEPENDS+=	${PYPKGPREFIX}-coloredlogs-[0-9]*:../../devel/py-coloredlogs
DEPENDS+=	${PYPKGPREFIX}-plotly>=5.1.8:../../graphics/py-plotly
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-rich>=10:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-yaml>=4:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-spectra>=0.0.10:../../graphics/py-spectra
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-natsort-[0-9]*:../../textproc/py-natsort

# test status as of 1.25.2
# 44 failed, 46 passed, 357 errors

post-patch:
	${RM} ${WRKSRC}/multiqc/multiqc.py.orig

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
