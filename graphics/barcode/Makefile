# $NetBSD: Makefile,v 1.2 2002/02/18 15:14:20 seb Exp $
#

DISTNAME=	barcode-0.96
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}

MAINTAINER=	dillo@netbsd.org
HOMEPAGE=	http://gnu.systemy.it/software/barcode/
COMMENT=	create bar codes as EPS (program and library)

GNU_CONFIGURE=	YES
MAKE_ENV+=	AWK="${AWK}"

INFO_FILES=	barcode.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
