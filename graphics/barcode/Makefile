# $NetBSD: Makefile,v 1.5 2003/07/21 16:51:37 martti Exp $
#

DISTNAME=	barcode-0.96
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://gnu.systemy.it/software/barcode/
COMMENT=	Create bar codes as EPS (program and library)

GNU_CONFIGURE=	YES
MAKE_ENV+=	AWK="${AWK}"

USE_NEW_TEXINFO=	YES
INFO_FILES=	barcode.info

.include "../../mk/bsd.pkg.mk"
