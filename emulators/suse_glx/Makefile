# $NetBSD: Makefile,v 1.8 2002/02/21 17:28:40 martti Exp $
#

DISTNAME=		suse_glx-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x3d1/} \
			ftp://ftp.suse.com/pub/suse/i386/update/${SUSE_VERSION}/x3d1/
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GLX binaries

DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		glx-000229-53.i386.rpm

.include "../suse_linux/Makefile.common"
