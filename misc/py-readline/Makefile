# $NetBSD: Makefile,v 1.10 1999/07/13 01:20:12 jlam Exp $
#

DISTNAME=	py152
PKGNAME=	py-readline-1.5.2
WRKSRC=		${WRKDIR}/Python-1.5.2/Modules
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/tut/interacting.html

DEPENDS+=	python-1.5.2:../../lang/python
DEPENDS+=	readline-4.0:../../devel/readline

DIST_SUBDIR=	python
ALL_TARGET=	default
EXTRACT_ELEMENTS=	Python-1.5.2/Modules/readline.c

PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config

.if ${MACHINE_ARCH} == "sparc64"
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
