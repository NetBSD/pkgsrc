# $NetBSD: Makefile,v 1.1 2023/07/22 13:18:52 bacon Exp $

DISTNAME=	multiqc-1.14
PKGNAME=	${PYPKGPREFIX}-multiqc-1.14
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=m/multiqc/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/multiqc
COMMENT=	Aggregate bioinformatics analysis reports across samples and tools
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.1.1:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.5.1:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-coloredlogs-[0-9]*:../../devel/py-coloredlogs
DEPENDS+=	${PYPKGPREFIX}-future>0.14.0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-yaml>=4:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rich>=10:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-rich-click-[0-9]*:../../devel/py-rich-click
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-spectra>=0.0.10:../../graphics/py-spectra
DEPENDS+=	${PYPKGPREFIX}-lzstring>0:../../archivers/py-lzstring

post-patch:
	${RM} ${WRKSRC}/multiqc/multiqc.py.orig

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
