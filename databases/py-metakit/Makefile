# $NetBSD: Makefile,v 1.10 2004/07/22 09:16:00 recht Exp $
#

DISTNAME=	metakit-2.4.9.3
PKGNAME=	${PYPKGPREFIX}-metakit-2.4.9.3
CATEGORIES=	databases python
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

WRKSRC=		${WRKDIR}/metakit-2.4.9.3/builds
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+= --with-python=${LOCALBASE}/${PYINC},${LOCALBASE}/${PYSITELIB}
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes
ALL_TARGET=	python
INSTALL_TARGET=	install-python
MAKE_ENV+=	PYINC=${LOCALBASE}/${PYINC} PYSITELIB=${LOCALBASE}/${PYSITELIB}
PY_PATCHPLIST=	yes

.include "../../databases/metakit-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
