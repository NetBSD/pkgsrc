# $NetBSD: Makefile,v 1.1.1.1 2002/01/15 17:11:03 drochner Exp $
#

DISTNAME=	Python-2.2
PKGNAME=	python22-2.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-threads

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2.2

.include "../../mk/bsd.pkg.mk"
