# $NetBSD: Makefile,v 1.1.1.1 1999/10/29 00:14:07 abs Exp $
#

DISTNAME=	vilearn-1.0
CATEGORIES=	editors misc
MASTER_SITES=	ftp://terminator.rs.itd.umich.edu/unix/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.umich.edu/~rsug/misc/vilearn.html

EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SED} '1,/^wes$$/d' | ${SH}

.include "../../mk/bsd.pkg.mk"
