# $NetBSD: Makefile,v 1.6 2001/02/17 17:51:33 wiz Exp $
# FreeBSD Id: Makefile,v 1.5 1998/10/21 00:57:27 steve Exp
#

DISTNAME=	LPRng-3.6.26
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.lprng.com/
COMMENT=	The "meta-package" for LPRng, Enhanced Printer Spooler

DEPENDS+=		LPRng-core-3.6.26:../../print/LPRng-core
DEPENDS+=		LPRng-doc-3.6.13:../../print/LPRng-doc

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_PATCH=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
