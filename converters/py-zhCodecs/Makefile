# $NetBSD: Makefile,v 1.8 2004/04/24 00:35:37 snj Exp $

DISTNAME=	ChineseCodecs1.2.0
PKGNAME=	${PYPKGPREFIX}-zhCodecs-1.2.0
CATEGORIES=	converters devel
MASTER_SITES=	ftp://ftp.shellhung.org/pub/OpenBSD/packages/chinese/ \
		ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/python-codecs/
COMMENT=	Python Unicode codecs for Chinese charsets

WRKSRC=		${WRKDIR}/${DISTNAME}/Python
PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined
USE_BUILDLINK3=	yes

post-extract:
	@${CHMOD} 711 ${WRKSRC}/chinesetw

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
