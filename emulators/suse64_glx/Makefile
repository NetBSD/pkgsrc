# $NetBSD: Makefile,v 1.6 2003/06/02 01:19:54 jschauma Exp $

DISTNAME=		suse_glx-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.suse.com/pub/suse/discontinued/i386/update/${SUSE_VERSION}/x3d1/
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GLX binaries

DEPENDS+=		suse_x11-${SUSE_VERSION}*:../../emulators/suse64_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		glx-000229-53.i386.rpm

.include "../suse64_linux/Makefile.common"
<<<<<<< Makefile
<<<<<<< Makefile
.include "../../mk/bsd.pkg.mk"
=======
.include "../../mk.bsd.pkg.mk"
>>>>>>> 1.4
=======
.include "../../mk/bsd.pkg.mk"
>>>>>>> 1.5
