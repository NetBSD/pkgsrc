# $NetBSD: Makefile,v 1.2 2002/01/31 23:18:09 wiz Exp $
#

DISTNAME=	py152
PKGNAME=	python15-1.5.2
WRKSRC=		${WRKDIR}/Python-1.5.2
CATEGORIES=	lang
MASTER_SITES=	http://www.python.org/ftp/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-thread

INSTALL_TARGET=	altinstall

.include "../../mk/bsd.pkg.mk"
