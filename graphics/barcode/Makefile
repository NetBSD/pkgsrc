# $NetBSD: Makefile,v 1.8 2005/03/18 14:44:58 wiz Exp $
#

DISTNAME=	barcode-0.98
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://ar.linux.it/software/barcode/
COMMENT=	Create bar codes as EPS (program and library)

GNU_CONFIGURE=	YES
MAKE_ENV+=	AWK="${AWK}"

INFO_FILES=	barcode.info

# man/man1/barcode.1
CONFLICTS+=	xscreensaver-[0-9]*

.include "../../mk/bsd.pkg.mk"
