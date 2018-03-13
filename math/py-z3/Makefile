# $NetBSD: Makefile,v 1.1 2018/03/13 00:36:05 khorben Exp $

.include "../../math/z3/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Python bindings for the Z3 theorem prover / SMT solver

CONFIGURE_ARGS+=	--python
NO_BUILD=	yes
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	27

PYZ3DIR=		${PREFIX}/${PYSITELIB}/z3
INSTALLATION_DIRS+=	${PYZ3DIR}
INSTALLATION_DIRS+=	${PYZ3DIR}/lib

do-install:
	${LN} -s ${LIBDIR}/libz3.so ${DESTDIR}${PYZ3DIR}/lib/libz3.so
	${INSTALL_DATA} ${WRKSRC}/build/python/z3/*.py ${DESTDIR}${PYZ3DIR}
	${PY_COMPILE_ALL} ${DESTDIR}${PYZ3DIR}

.include "../../lang/python/extension.mk"
.include "../../math/z3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
