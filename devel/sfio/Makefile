# $NetBSD: Makefile,v 1.2 1998/11/02 21:18:13 agc Exp $
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

post-patch:
	${MV} ${WRKSRC}/man/man3/sfio.3 ${WRKSRC}/man/man3/sfio.3.in
	${SED} -e 's|@prefix@|${PREFIX}|g' ${WRKSRC}/man/man3/sfio.3.in \
			> ${WRKSRC}/man/man3/sfio.3

.include "../../mk/bsd.pkg.mk"
