# $NetBSD: Makefile,v 1.15 2012/10/31 11:16:51 asau Exp $

DISTNAME=	cxref-1.6d
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
