# $NetBSD: Makefile,v 1.3 2009/02/11 22:49:07 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/newt/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-newt-${VERSION}
COMMENT=	Windowing toolkit based on libslang (Python bindings)

PYTHON_VERSIONS_ACCEPTED=	25 24

PY_PATCHPLIST=	yes
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	${PREFIX}/${PYSITELIB}

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -fPIC -c -o snackmodule.o snackmodule.c; \
	${CC} --shared ${CFLAGS} -o _snackmodule.so snackmodule.o -Wl,-R${BUILDLINK_PREFIX.newt}/lib -L${BUILDLINK_PREFIX.newt}/lib -lnewt
	${PYTHONBIN} -m py_compile ${WRKSRC}/snack.py

do-install:
	${INSTALL_LIB} ${WRKSRC}/_snackmodule.so ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_LIB} ${WRKSRC}/snack.p* ${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../devel/newt/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
