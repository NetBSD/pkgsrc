# $NetBSD: Makefile,v 1.1.1.1 2002/01/29 19:13:22 drochner Exp $
#

DISTNAME=	py152
PKGNAME=	python15-1.5.2
CATEGORIES=	lang
MASTER_SITES=	http://www.python.org/ftp/python/src/
EXTRACT_SUFX=	.tgz
WRKSRC=		${WRKDIR}/Python-1.5.2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-thread

INSTALL_TARGET=	altinstall

.include "../../mk/bsd.pkg.mk"
