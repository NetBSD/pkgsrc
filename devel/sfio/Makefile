# $NetBSD: Makefile,v 1.26 2017/09/04 18:00:54 wiz Exp $
#

# pkgsrc/mail/sendmail (as of 8.11.0) specifically wants 1999, not 2000.
# if you upgrade it, please check if sendmail works right.
#
# the original distribution requires us to put name onto web form, however,
# the license term permits redistribution.  a copy of the distribution kit
# is put into ${MASTER_SITE_LOCAL}.
#
DISTNAME=	sfio_1999.src.unix
PKGNAME=	sfio-1999
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.cpio

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://akpublic.research.att.com/sw/tools/sfio/
COMMENT=	Safe and Fast IO library

MAKE_JOBS_SAFE=	no
MAKE_FLAGS+=	MKPROFILE=yes

WRKSRC=		${WRKDIR}

AUTO_MKDIRS=			yes

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=parentheses
.endif

post-patch:
	${MV} ${WRKSRC}/man/man3/sfio.3 ${WRKSRC}/man/man3/sfio.3.in
	${SED} -e 's|@prefix@|${PREFIX}|g' ${WRKSRC}/man/man3/sfio.3.in \
			> ${WRKSRC}/man/man3/sfio.3

.include "../../mk/bsd.pkg.mk"
