# $NetBSD: Makefile,v 1.14 2004/11/28 16:04:00 martti Exp $
# FreeBSD Id: Makefile,v 1.5 1998/10/21 00:57:27 steve Exp

DISTNAME=	LPRng-3.6.28
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.lprng.com/
COMMENT=	"meta-package" for LPRng, Enhanced Printer Spooler

DEPENDS+=	LPRng-core-3.8.28:../../print/LPRng-core
DEPENDS+=	LPRng-doc-3.6.13:../../print/LPRng-doc

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
