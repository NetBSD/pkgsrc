# $NetBSD: Makefile,v 1.3 2003/06/02 01:19:53 jschauma Exp $

DISTNAME=		shlibs5
PKGREVISION=		1
PKGNAME=		suse_libc5-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for libc5 binaries

DEPENDS+=		suse_compat-${SUSE_VERSION}*:../suse64_compat

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../suse64_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
