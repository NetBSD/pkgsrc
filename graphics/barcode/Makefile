# $NetBSD: Makefile,v 1.4 2003/07/17 21:40:12 grant Exp $
#

DISTNAME=	barcode-0.96
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://gnu.systemy.it/software/barcode/
COMMENT=	create bar codes as EPS (program and library)

GNU_CONFIGURE=	YES
MAKE_ENV+=	AWK="${AWK}"

USE_NEW_TEXINFO=	YES
INFO_FILES=	barcode.info

.include "../../mk/bsd.pkg.mk"
