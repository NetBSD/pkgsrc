# $NetBSD: Makefile,v 1.61 2022/11/25 13:13:54 wiz Exp $

DISTNAME=	protobuf-4.21.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/protobuf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.google.com/protocol-buffers/
COMMENT=	Python bindings for protobuf
LICENSE=	modified-bsd

USE_LANGUAGES+=	c c++11

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=		PROTOC=${PREFIX}/bin/protoc
PYSETUPBUILDARGS=	--cpp_implementation
PYSETUPINSTALLARGS=	--cpp_implementation

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == py311
# as of 4.21.9, the sources do contain outdated code that only supports Python < 3.11
# https://github.com/protocolbuffers/protobuf/issues/11031#issuecomment-1321390551
# use the binary wheel for now, since it does support Python 3.11
NO_BUILD=	yes
MASTER_SITES=	https://files.pythonhosted.org/packages/0b/c3/bfe27bff58e895261e5054f38e9f12fcccd67d70ccad66c22ba987b17fc9/
PLIST_SRC=	PLIST.py311
.include "../../lang/python/wheel.mk"

post-install:
.  for f in lib/python3.11/site-packages/google/protobuf/internal/_parameterized.py
	cd ${DESTDIR}${PREFIX} && \
	${SED} -e s",/usr/bin/env python,${PYTHONBIN}," ${f} > ${f}.patched && ${MV} ${f}.patched ${f}
.  endfor
.else
.include "../../lang/python/egg.mk"
.endif

.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
