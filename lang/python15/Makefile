# $NetBSD: Makefile,v 1.3 2003/06/02 01:18:57 jschauma Exp $
#

DISTNAME=	py152
PKGNAME=	python15-1.5.2
WRKSRC=		${WRKDIR}/Python-1.5.2
CATEGORIES=	lang
MASTER_SITES=	http://www.python.org/ftp/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-thread

INSTALL_TARGET=	altinstall

.include "../../mk/bsd.pkg.mk"
