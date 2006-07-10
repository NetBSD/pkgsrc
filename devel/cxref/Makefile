# $NetBSD: Makefile,v 1.11 2006/07/10 11:59:09 rillig Exp $
#

DISTNAME=	cxref-1.6a
CATEGORIES=	devel lang
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-cxref/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/cxref/
COMMENT=	C Cross Referencing & Documenting tool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cxref-cpp
CONFIGURE_ARGS+=	PERL=""	# Don't regenerate documentation
USE_TOOLS+=		gmake	# uses the $< variable in the GNU way
USE_TOOLS+=		lex yacc

.include "../../mk/bsd.pkg.mk"
