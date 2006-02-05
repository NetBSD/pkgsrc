# $NetBSD: Makefile,v 1.15 2006/02/05 23:08:36 joerg Exp $
#

DISTNAME=	metakit-2.4.9.3
PKGNAME=	${PYPKGPREFIX}-metakit-2.4.9.3
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

WRKSRC=		${WRKDIR}/metakit-2.4.9.3/builds
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../unix/configure
CONFIG_GUESS_OVERRIDE=	../unix/scripts/config.guess
CONFIG_SUB_OVERRIDE=	../unix/scripts/config.sub
CONFIG_STATUS_OVERRIDE=	../unix/scripts/config.status
CONFIGURE_ARGS+= --with-python=${LOCALBASE}/${PYINC},${LOCALBASE}/${PYSITELIB}
USE_LIBTOOL=	yes
BUILD_TARGET=	python
INSTALL_TARGET=	install-python
MAKE_ENV+=	PYINC=${LOCALBASE}/${PYINC} PYSITELIB=${LOCALBASE}/${PYSITELIB}
PY_PATCHPLIST=	yes

.include "../../databases/metakit-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
