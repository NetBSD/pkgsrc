# $NetBSD: Makefile,v 1.6 1998/11/13 01:34:24 frueauf Exp $
#

DISTNAME=	pyth151
PKGNAME=	py-readline-1.5.1
WRKSRC=		${WRKDIR}/Python-1.5.1/Modules
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/doc/tut/interacting.html

DEPENDS+=	python-1.5.1:../../lang/python
DEPENDS+=	readline-2.2:../../devel/readline

NOT_FOR_ARCHS=  alpha # possibly broken

DIST_SUBDIR=	python
ALL_TARGET=	default
EXTRACT_AFTER_ARGS=	Python-1.5.1/Modules/readline.c

PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="Needs dynamic loading"
.endif

do-configure:
	${SED} 's%@LOCALBASE@%${LOCALBASE}%g' ${FILESDIR}/Setup.in \
	 >${WRKSRC}/Setup.in
	(cd ${WRKSRC}; \
	 ${LN} -s ${PYTHON_CONFIGDIR}/Makefile.pre.in; \
	 ${MAKE} -f Makefile.pre.in boot)

do-install:
	${INSTALL_DATA} ${WRKSRC}/readline.so ${LOCALBASE}/lib/python1.5/lib-dynload

.include "../../mk/bsd.pkg.mk"
