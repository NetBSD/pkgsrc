# $NetBSD: Makefile,v 1.3 2003/07/03 13:14:28 seb Exp $
#

DISTNAME=	barcode-0.96
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}

MAINTAINER=	dillo@netbsd.org
HOMEPAGE=	http://gnu.systemy.it/software/barcode/
COMMENT=	create bar codes as EPS (program and library)

GNU_CONFIGURE=	YES
MAKE_ENV+=	AWK="${AWK}"

USE_NEW_TEXINFO=	YES
INFO_FILES=	barcode.info

.include "../../mk/bsd.pkg.mk"
