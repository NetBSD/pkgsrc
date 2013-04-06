# $NetBSD: Makefile,v 1.9 2013/04/06 12:04:00 rodent Exp $
#

DISTNAME=	vilearn-1.0
CATEGORIES=	editors misc
MASTER_SITES=	#
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://vilearn.org/
COMMENT=	Online vi tutorial, from basic to advanced

EXTRACT_CMD=	${GZCAT} $$extract_file | ${SED} '1,/^wes$$/d' | ${SH}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
