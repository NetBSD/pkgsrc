# $NetBSD: Makefile,v 1.4 2019/08/07 21:48:01 brook Exp $

CATEGORIES=	devel R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://irkernel.github.io/
COMMENT=	Native R kernel for the Jupyter notebook

R_PKGNAME=	IRkernel
R_PKGVER=	1.0.2

DEPENDS+=	R-IRdisplay>=0.3.0.9999:../../devel/R-IRdisplay
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-evaluate>=0.10:../../devel/R-evaluate
DEPENDS+=	R-repr>=0.4.99:../../devel/R-repr
DEPENDS+=	R-uuid>=0.1.2:../../devel/R-uuid
DEPENDS+=	R-pbdZMQ>=0.2.1:../../net/R-pbdZMQ
DEPENDS+=	R-digest>=0.6.15:../../security/R-digest
DEPENDS+=	R-jsonlite>=0.9.6:../../textproc/R-jsonlite

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"

INSTALLATION_DIRS+=	share/jupyter/kernels/ir

post-install:
.for f in kernel.js logo-64x64.png
	${LN} -s ${DESTDIR}${PREFIX}/lib/R/library/${R_PKGNAME}/kernelspec/${f} \
		${DESTDIR}${PREFIX}/share/jupyter/kernels/ir/
.endfor
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/lib/R/library/${R_PKGNAME}/kernelspec/kernel.json \
		${DESTDIR}${PREFIX}/share/jupyter/kernels/ir/

.include "../../mk/bsd.pkg.mk"
