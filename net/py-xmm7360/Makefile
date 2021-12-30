# $NetBSD: Makefile,v 1.3 2021/12/30 13:05:40 adam Exp $

DISTNAME=	xmm7360-0.20200727
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=xmm7360/}
GITHUB_PROJECT=	xmm7360-pci
GITHUB_TAG=	0060149958d00b9cec87b73cd610c136f69e5275

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xmm7360/xmm7360-pci
COMMENT=	Network initialization for L850-GL / Intel XMM7360 driver
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-configargparse>=1.2.3:../../devel/py-configargparse

NO_BUILD=       yes
XMM_DIR=	${PYSITELIB}/xmm7360

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON=                 rpc/open_xdatachannel.py rpc/rpc.py
INSTALLATION_DIRS+=             bin ${XMM_DIR}
PY_PATCHPLIST=                  yes

do-configure:
	# XXX: Blank, but we can't define NO_CONFIGURE and use REPLACE_PYTHON...

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rpc/rpc.py \
                ${DESTDIR}${PREFIX}/${XMM_DIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/rpc/rpc_call_ids.py \
                ${DESTDIR}${PREFIX}/${XMM_DIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/rpc/rpc_unsol_table.py \
                ${DESTDIR}${PREFIX}/${XMM_DIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/rpc/open_xdatachannel.py \
                ${DESTDIR}${PREFIX}/bin/open_xdatachannel.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
