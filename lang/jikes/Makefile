# $NetBSD: Makefile,v 1.31 2005/03/23 11:01:56 wiz Exp $
#

DISTNAME=	jikes-1.22
PKGREVISION=	2
CATEGORIES=	lang java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jikes/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jikes.sourceforge.net/
COMMENT=	Java source to byte-code compiler

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
UNLIMIT_RESOURCES=      datasize

# enable "-source 1.5" -- not complete, but does not break normal compiles
CONFIGURE_ARGS+=	--enable-source15

USE_GNU_TOOLS+=	make	# uses multi-line comments with \ (naughty hack!)

.include "../../mk/bsd.pkg.mk"
