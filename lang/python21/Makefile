# $NetBSD: Makefile,v 1.4 2002/01/22 13:05:03 drochner Exp $
#

DISTNAME=	Python-2.1.2
PKGNAME=	python21-2.1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.1.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-threads

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2.1

.include "../../mk/bsd.pkg.mk"
