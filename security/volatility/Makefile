# $NetBSD: Makefile,v 1.17 2022/06/30 11:18:48 nia Exp $

DISTNAME=	volatility-2.6.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=volatilityfoundation/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.volatilityfoundation.org/
COMMENT=	Advanced memory forensics framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
# Recommended packages
# from https://github.com/volatilityfoundation/volatility/wiki/Installation
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow6
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-distorm3-[0-9]*:../../devel/py-distorm3
DEPENDS+=	${PYPKGPREFIX}-openpyxl-[0-9]*:../../textproc/py-openpyxl
# does not support python 2.7
#DEPENDS+=	${PYPKGPREFIX}-ujson-[0-9]*:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-yara-[0-9]*:../../security/py-yara

REPLACE_PYTHON=	tools/vtype_diff.py

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
