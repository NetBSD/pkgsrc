# $NetBSD: Makefile,v 1.5 2003/07/21 16:36:14 martti Exp $

DISTNAME=	ChineseCodecs1.2.0
PKGNAME=	${PYPKGPREFIX}-zhCodecs-1.2.0
WRKSRC=		${WRKDIR}/${DISTNAME}/Python
CATEGORIES=	converters devel
MASTER_SITES=	ftp://ftp.shellhung.org/pub/OpenBSD/packages/chinese/ \
		ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/python-codecs/
COMMENT=	Python Unicode codecs for Chinese charsets

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined

post-extract:
	@${CHMOD} 711 ${WRKSRC}/chinesetw

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
