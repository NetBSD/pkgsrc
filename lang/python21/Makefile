# $NetBSD: Makefile,v 1.1.1.1 2001/08/07 14:38:07 drochner Exp $
#

DISTNAME=	Python-2.1.1
PKGNAME=	python21-2.1.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.1.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-threads

INSTALL_TARGET=	altinstall

.include "../../mk/bsd.pkg.mk"
