# $NetBSD: Makefile,v 1.23 2017/09/04 18:08:19 wiz Exp $

DISTNAME=	ChineseCodecs1.2.0
PKGNAME=	${PYPKGPREFIX}-zhCodecs-1.2.0
PKGREVISION=	1
CATEGORIES=	converters devel python
MASTER_SITES=	ftp://ftp.shellhung.org/pub/OpenBSD/packages/chinese/
MASTER_SITES+=	ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/python-codecs/
COMMENT=	Python Unicode codecs for Chinese charsets

WRKSRC=		${WRKDIR}/${DISTNAME}/Python
PYDISTUTILSPKG=	# defined

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

post-extract:
	@${CHMOD} 711 ${WRKSRC}/chinesetw

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
