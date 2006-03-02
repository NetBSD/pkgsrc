# $NetBSD: Makefile,v 1.7 2006/03/02 19:28:27 drochner Exp $
#

DISTNAME=	cxref-1.6a
CATEGORIES=	devel lang
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-cxref/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/cxref/
COMMENT=	C Cross Referencing & Documenting tool

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-cxref-cpp
USE_GNU_TOOLS+=	make

.include "../../mk/bsd.pkg.mk"
