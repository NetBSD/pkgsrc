# $NetBSD: Makefile,v 1.3 2003/06/02 01:19:55 jschauma Exp $

DISTNAME=		suse_audio-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=snd1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for audio libraries

DEPENDS+=		suse_base-${SUSE_VERSION}*:../suse64_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		audiofil.rpm

.include "../suse64_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
