# $NetBSD: Makefile,v 1.1 1998/08/07 14:50:49 tsarna Exp $

DISTNAME=	pycrypt100
PKGNAME=	py-crypto-1.0.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cwi.nl/pub/pct/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org

DEPENDS+=	python-1.5.1:../../lang/python

MIRROR_DISTFILE=no
RESTRICTED=	crypto

WRKSRC=		${WRKDIR}/Extensions/Crypto
MAKE_FLAGS=	'OPT=${CFLAGS}'

INFO_FILES=	pct.info

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "alpha"
IGNORE="Needs dynamic loading"
.endif

post-extract:
	@(cd ${WRKDIR}; tar xf pycrypt.tar)

do-configure:
	@(cd ${WRKSRC}; ${PREFIX}/bin/python buildkit)
	${CP} ${PREFIX}/lib/python1.5/config/Makefile.pre.in ${WRKSRC}/src
	${CP} ${WRKSRC}/Setup.in ${WRKSRC}/src
	@(cd ${WRKSRC}/src; make -f Makefile.pre.in boot)

do-build:
	@(cd ${WRKSRC}/src; make)
	${PREFIX}/bin/python ${PREFIX}/lib/python1.5/compileall.py \
		${WRKSRC}/Lib
	${PREFIX}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py \
		${WRKSRC}/Lib

do-install:
	(cd ${WRKSRC}/Lib ; ${INSTALL_DATA} *.py *.pyc *.pyo \
		${PREFIX}/lib/python1.5/site-packages)
	(cd ${WRKSRC}/src ; ${INSTALL_DATA} *.so \
		${PREFIX}/lib/python1.5/site-packages)
	(cd ${WRKSRC}/Doc ; ${INSTALL_MAN} *info* \
		${PREFIX}/info)

.include "../../mk/bsd.pkg.mk"
