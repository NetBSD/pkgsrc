# $NetBSD: Makefile,v 1.1.1.1 2002/06/15 08:18:15 shell Exp $

DISTNAME=	ChineseCodecs1.2.0
PKGNAME=	${PYPKGPREFIX}-zhCodecs-1.2.0
CATEGORIES=	converters devel
MASTER_SITES=	ftp://ftp.shellhung.org/pub/OpenBSD/packages/chinese/ \
		ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://www.sourceforge.net/python-codecs/
COMMENT=	python Unicode codecs for Chinese charsets

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

post-extract:
	@${CHMOD} 711 ${WRKSRC}/chinesetw

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
