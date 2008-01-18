# $NetBSD: Makefile,v 1.9 2008/01/18 05:09:38 tnn Exp $
#

DISTNAME=		tpm-1.1b
PKGNAME=		${DISTNAME:S/tpm/libtcpa/}
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		${HOMEPAGE}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} tcpa_man_20031210.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.research.ibm.com/gsal/tcpa/
COMMENT=		TCPA libraries and test programs from IBM

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/TPM

SITES.tcpa_man_20031210.tgz= http://www.citi.umich.edu/u/rwash/projects/trusted/

BUILD_DIRS=		libtcpa examples
INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man3 share/doc/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libtcpa/libtcpa.a ${PREFIX}/lib
	for f in tcpa_demo takeown createkey loadkey evictkey signfile	\
		verifyfile sealfile unsealfile; do			\
		${INSTALL_PROGRAM} ${WRKSRC}/examples/$${f} ${PREFIX}/bin; \
	done
	for f in ${WRKDIR}/tcpa_man/*.3; do			\
		${INSTALL_MAN} $${f} ${PREFIX}/${PKGMANDIR}/man3;	\
	done
	${INSTALL_DATA} ${WRKSRC}/libtcpa/License ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
