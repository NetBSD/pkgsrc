# $NetBSD: Makefile,v 1.7 2004/01/20 12:19:17 agc Exp $
#

DISTNAME=	py152
PKGNAME=	python15-1.5.2
CATEGORIES=	lang
MASTER_SITES=	http://www.python.org/ftp/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

WRKSRC=		${WRKDIR}/Python-1.5.2
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-thread

INSTALL_TARGET=	altinstall

.include "../../mk/bsd.pkg.mk"
