# $NetBSD: Makefile,v 1.6 2003/07/17 21:36:01 grant Exp $

DISTNAME=		suse_x11-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.suse.com/pub/suse/discontinued/i386/update/${SUSE_VERSION}/x1/ \
			${MASTER_SITE_SUSE:=x1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for X11 binaries

DEPENDS+=		suse_base-${SUSE_VERSION}*:../suse64_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		xshared-3.3.6-43.i386.rpm xpm.rpm

.include "../suse64_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
