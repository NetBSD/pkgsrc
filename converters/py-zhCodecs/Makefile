# $NetBSD: Makefile,v 1.29 2022/01/22 15:43:03 wiz Exp $

DISTNAME=	ChineseCodecs1.2.0
PKGNAME=	${PYPKGPREFIX}-zhCodecs-1.2.0
PKGREVISION=	2
CATEGORIES=	converters devel python
MASTER_SITES=	# ftp://ftp.shellhung.org/pub/OpenBSD/packages/chinese/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/python-codecs/
COMMENT=	Python Unicode codecs for Chinese charsets

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

PYTHON_VERSIONS_ACCEPTED=	27
EGG_NAME=			ChineseCodecs-1.1.0

post-extract:
	${CHMOD} 711 ${WRKSRC}/chinesetw

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
