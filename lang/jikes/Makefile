# $NetBSD: Makefile,v 1.30 2005/01/30 23:18:38 jmmv Exp $
#

DISTNAME=	jikes-1.22
PKGREVISION=	2
CATEGORIES=	lang java
MASTER_SITES=	http://oss.software.ibm.com/pub/${DISTNAME:S,-,/,}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www10.software.ibm.com/developerworks/opensource/jikes/
COMMENT=	Java source to byte-code compiler

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
UNLIMIT_RESOURCES=      datasize

# enable "-source 1.5" -- not complete, but does not break normal compiles
CONFIGURE_ARGS+=	--enable-source15

USE_GNU_TOOLS+=	make	# uses multi-line comments with \ (naughty hack!)

.include "../../mk/bsd.pkg.mk"
