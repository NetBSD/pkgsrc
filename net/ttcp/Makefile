# $NetBSD: Makefile,v 1.10 1998/04/15 10:38:40 agc Exp $
#

DISTNAME=	ttcp
PKGNAME=	${DISTNAME}-1.12
CATEGORIES=	net
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thorpej@NetBSD.ORG

NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

.include "../../mk/bsd.pkg.mk"
