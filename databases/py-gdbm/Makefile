# $NetBSD: Makefile,v 1.2 1998/08/20 15:16:44 tsarna Exp $
#

DISTNAME=	pyth151
PKGNAME=	py-gdbm-1.5.1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/doc/lib/module-gdbm.html

DEPENDS+=	python-1.5.1:../../lang/python	\
		gdbm-1.7.3:../../databases/gdbm

WRKSRC=		${WRKDIR}/Python-1.5.1/Modules
ALL_TARGET=	default
EXTRACT_AFTER_ARGS=	Python-1.5.1/Modules/gdbmmodule.c

PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config/

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "alpha"
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
