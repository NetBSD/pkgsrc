# $NetBSD: Makefile,v 1.4 2003/03/26 04:05:50 jschauma Exp $

DISTNAME=		suse_libjpeg-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.suse.com/pub/suse/discontinued/i386/update/${SUSE_VERSION}/gra1/

DISTFILES=		${RPMFILES}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for jpeg binary

DEPENDS+=		suse_base-${SUSE_VERSION}*:../suse64_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		libjpeg-6.2.0-62.i386.rpm

.include "../suse64_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
