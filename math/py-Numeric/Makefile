# $NetBSD: Makefile,v 1.11 1998/09/27 22:24:44 tsarna Exp $

DISTNAME=	LLNLPython4
PKGNAME=	py-Numeric-1.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/sigs/matrix-sig/

DEPENDS+=	python-1.5.1:../../lang/python

NOT_FOR_ARHCS=	alpha # broken, needs investigation

WRKSRC=		${WRKDIR}/LLNLPython4/Numerical
ALL_TARGET=	default
MAKE_FLAGS=	'OPT=${CFLAGS}'
DOCDIR=		${PREFIX}/share/doc/py-Numeric

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="Needs dynamic loading"
.endif

do-configure:
	@(cd ${WRKSRC} && PREFIX=${PREFIX} python makethis.py)

post-install:
	@(cd ${WRKSRC}/Lib ; \
	${PREFIX}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py . ; \
	${INSTALL_DATA} *.py *.pyc *.pyo ${PREFIX}/lib/python1.5/site-packages)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
