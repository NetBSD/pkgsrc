# $NetBSD: Makefile,v 1.1.1.1 1998/11/02 14:43:17 agc Exp $
#

DISTNAME=       sfio_1998.src.unix
PKGNAME=        sfio-1998
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.cpio

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://akpublic.research.att.com/sw/tools/sfio/

NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	cd ${WRKDIR} ; pax -r < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

.include "../../mk/bsd.pkg.mk"
