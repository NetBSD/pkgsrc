# $NetBSD: Makefile,v 1.2 2018/12/21 06:14:14 wen Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=IRkernel/}
GITHUB_PROJECT=	${R_PKGNAME}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://irkernel.github.io/
COMMENT=	R kernel for Jupyter Notebook

R_PKGNAME=	IRkernel
R_PKGVER=	0.8.14

DEPENDS+=	R-crayon-[0-9]*:../../devel/R-crayon
DEPENDS+=	R-digest-[0-9]*:../../security/R-digest
DEPENDS+=	R-evaluate>=0.10:../../devel/R-evaluate
DEPENDS+=	R-IRdisplay-[0-9]*:../../devel/R-IRdisplay
DEPENDS+=	R-jsonlite>=0.9.6*:../../textproc/R-jsonlite
DEPENDS+=	R-pbdZMQ>=0.2.1:../../net/R-pbdZMQ
DEPENDS+=	R-repr>=0.4.99:../../devel/R-repr
DEPENDS+=	R-uuid-[0-9]*:../../devel/R-uuid

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"

INSTALLATION_DIRS+=	share/jupyter/kernels/ir

post-extract:
	${MV} ${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG} ${WRKSRC}

post-install:
.for f in kernel.js logo-64x64.png
	${LN} -s ${DESTDIR}${PREFIX}/lib/R/library/${R_PKGNAME}/kernelspec/${f} \
		${DESTDIR}${PREFIX}/share/jupyter/kernels/ir/
.endfor
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/lib/R/library/${R_PKGNAME}/kernelspec/kernel.json \
		${DESTDIR}${PREFIX}/share/jupyter/kernels/ir/

.include "../../mk/bsd.pkg.mk"
