# $NetBSD: Makefile,v 1.12 2006/10/14 08:00:47 wiz Exp $

DISTNAME=	ChineseCodecs1.2.0
PKGNAME=	${PYPKGPREFIX}-zhCodecs-1.2.0
PKGREVISION=	1
CATEGORIES=	converters devel python
MASTER_SITES=	ftp://ftp.shellhung.org/pub/OpenBSD/packages/chinese/ \
		ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/python-codecs/
COMMENT=	Python Unicode codecs for Chinese charsets

WRKSRC=		${WRKDIR}/${DISTNAME}/Python
PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined

post-extract:
	@${CHMOD} 711 ${WRKSRC}/chinesetw

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
