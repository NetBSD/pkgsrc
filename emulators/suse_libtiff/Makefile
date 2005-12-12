# $NetBSD: Makefile,v 1.8 2005/12/12 14:43:25 joerg Exp $

DISTNAME=		libtiff
PKGNAME=		suse_${DISTNAME}-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the TIFF library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

NO_BUILD=		YES
EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
