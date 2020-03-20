# $NetBSD: Makefile,v 1.40 2020/03/20 11:57:55 nia Exp $
#

DISTNAME=	jikes-1.22
PKGREVISION=	3
CATEGORIES=	lang java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jikes/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jikes.sourceforge.net/
COMMENT=	Java source to byte-code compiler

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
UNLIMIT_RESOURCES=	datasize

# enable "-source 1.5" -- not complete, but does not break normal compiles
CONFIGURE_ARGS+=	--enable-source15

USE_TOOLS+=	gmake	# uses multi-line comments with \ (naughty hack!)

.include "../../mk/bsd.pkg.mk"
