# $NetBSD: Makefile,v 1.3 2005/11/03 23:58:41 agc Exp $

DISTNAME=	iscsi-Jan15
PKGNAME=	intel-iscsi-20040115
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=intel-iscsi/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/intel-iscsi
COMMENT=	Intel Lab's software reference implementation of iSCSI RFC 3720

WRKSRC=		${WRKDIR}/IntelLabs-v20-011504

do-build:
	cd ${WRKSRC}/src && ${MAKE} ufsdisk uramdisk ufsdisk_mmap usocktest utest ktest uosd

do-install:
	for f in ufsdisk uramdisk ufsdisk_mmap usocktest utest ktest uosd; do \
		${INSTALL_PROGRAM} ${WRKSRC}/src/$$f ${PREFIX}/bin;	\
	done

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
