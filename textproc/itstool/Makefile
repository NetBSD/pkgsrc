# $NetBSD: Makefile,v 1.16 2018/11/30 15:04:02 wiz Exp $

DISTNAME=	itstool-2.0.5
CATEGORIES=	textproc
MASTER_SITES=	http://files.itstool.org/itstool/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://itstool.org/
COMMENT=	ITS Tool allows you to translate XML documents with PO files
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

REPLACE_PYTHON=	${WRKSRC}/itstool.in

DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
