# $NetBSD: Makefile,v 1.14 2001/02/16 14:17:37 wiz Exp $
#

DISTNAME=	${PY_DISTNAME}
PKGNAME=	py-gdbm-${PY_VERSION}
WRKSRC=		${PY_WRKSRC}
CATEGORIES=	databases
MASTER_SITES=	${PY_MASTER_SITES}

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/doc/lib/module-gdbm.html
COMMENT=	Python interface to gdbm - GNU database manager

DEPENDS+=	gdbm>=1.7.3:../../databases/gdbm

EXTRACT_ELEMENTS=	${PY_MODULES}/gdbmmodule.c

do-configure: python-std-do-configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdbmmodule.so ${PY_LIBDIR}/lib-dynload

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
