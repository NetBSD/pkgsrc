# $NetBSD: Makefile,v 1.12 2004/12/03 15:14:53 wiz Exp $
#

DISTNAME=	metakit-2.4.9.3
PKGNAME=	${PYPKGPREFIX}-metakit-2.4.9.3
PKGREVISION=	1
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
BUILD_TARGET=	python
INSTALL_TARGET=	install-python
MAKE_ENV+=	PYINC=${LOCALBASE}/${PYINC} PYSITELIB=${LOCALBASE}/${PYSITELIB}
PY_PATCHPLIST=	yes

.include "../../databases/metakit-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
