# $NetBSD: Makefile,v 1.7 2004/02/14 17:21:36 jlam Exp $
#

DISTNAME=	metakit-2.4.8-38
PKGNAME=	${PYPKGPREFIX}-metakit-2.4.8
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

WRKSRC=		${WRKDIR}/metakit-2.4.8/builds
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+=	--with-tcl= --enable-python
USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes
ALL_TARGET=	python
INSTALL_TARGET=	install-python
MAKE_ENV+=	PYINC=${LOCALBASE}/${PYINC} PYSITELIB=${LOCALBASE}/${PYSITELIB}
PY_PATCHPLIST=	yes

.include "../../databases/metakit-lib/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
