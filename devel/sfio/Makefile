# $NetBSD: Makefile,v 1.4 2000/08/13 17:42:22 itojun Exp $
#

# pkgsrc/mail/sendmail (as of 8.11.0) specifically wants 1999, not 2000.
# if you upgrade it, please check if sendmail works right.
#
# the original distribution requires us to put name onto web form, however,
# the license term permits redistribution.  a copy of the distribution kit
# is put into ${MASTER_SITE_LOCAL}.
#
DISTNAME=       sfio_1999.src.unix
PKGNAME=        sfio-1999
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.cpio

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://akpublic.research.att.com/sw/tools/sfio/

NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	cd ${WRKDIR} ; ${PAX} -r < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-patch:
	${MV} ${WRKSRC}/man/man3/sfio.3 ${WRKSRC}/man/man3/sfio.3.in
	${SED} -e 's|@prefix@|${PREFIX}|g' ${WRKSRC}/man/man3/sfio.3.in \
			> ${WRKSRC}/man/man3/sfio.3

.include "../../mk/bsd.pkg.mk"
