# $NetBSD: Makefile,v 1.2 2001/02/16 14:40:54 wiz Exp $
#

DISTNAME=	vilearn-1.0
CATEGORIES=	editors misc
MASTER_SITES=	ftp://terminator.rs.itd.umich.edu/unix/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.umich.edu/~rsug/misc/vilearn.html
COMMENT=	online vi tutorial, from basic to advanced

EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SED} '1,/^wes$$/d' | ${SH}

.include "../../mk/bsd.pkg.mk"
