# $NetBSD: Makefile,v 1.10 2006/06/09 15:52:28 minskim Exp $
#

DISTNAME=	cxref-1.6a
CATEGORIES=	devel lang
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-cxref/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/cxref/
COMMENT=	C Cross Referencing & Documenting tool

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-cxref-cpp
USE_TOOLS+=		gmake	# uses the $< variable in the GNU way
USE_TOOLS+=	lex yacc

.include "../../mk/bsd.pkg.mk"
