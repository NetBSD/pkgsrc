# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:19 rillig Exp $
#

DISTNAME=	barcode-0.98
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://ar.linux.it/software/barcode/
COMMENT=	Create bar codes as EPS (program and library)

GNU_CONFIGURE=	YES
MAKE_ENV+=	AWK=${AWK:Q}

INFO_FILES=	barcode.info

# man/man1/barcode.1
CONFLICTS+=	xscreensaver-[0-9]*

.include "../../mk/bsd.pkg.mk"
