# $NetBSD: Makefile,v 1.19 2006/02/05 23:09:04 joerg Exp $

DISTNAME=		glx
PKGNAME=		suse_${DISTNAME}-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x3d1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GLX binaries

DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse_x11

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
