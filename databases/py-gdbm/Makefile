# $NetBSD: Makefile,v 1.11 2000/06/13 10:40:24 wiz Exp $
#

DISTNAME=	py152
PKGNAME=	py-gdbm-1.5.2
WRKSRC=		${WRKDIR}/Python-1.5.2/Modules
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/doc/lib/module-gdbm.html

DEPENDS+=	python-1.5.2:../../lang/python
DEPENDS+=	gdbm>=1.7.3:../../databases/gdbm

DIST_SUBDIR=	python

ALL_TARGET=	default

EXTRACT_ELEMENTS=	Python-1.5.2/Modules/gdbmmodule.c

PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config/

.if ${MACHINE_ARCH} == "sparc64"
IGNORE="Needs dynamic loading"
.endif

do-configure:
	${SED} -e 's%@LOCALBASE@%${LOCALBASE}%g' ${FILESDIR}/Setup.in \
	 >${WRKSRC}/Setup.in
	(cd ${WRKSRC}; \
	 ${CP} ${PYTHON_CONFIGDIR}/Makefile.pre.in .;\
	 ${MAKE} -f Makefile.pre.in boot;)

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdbmmodule.so ${LOCALBASE}/lib/python1.5/lib-dynload

.include "../../mk/bsd.pkg.mk"
