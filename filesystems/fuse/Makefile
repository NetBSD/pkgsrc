# $NetBSD: Makefile,v 1.9 2012/10/03 16:08:30 asau Exp $
#

DISTNAME=		fuse-2.8.4
PKGREVISION=		2
CATEGORIES=		filesystems
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fuse.sourceforge.net/
COMMENT=		Filesystem in Userspace

GNU_CONFIGURE=		yes

# FUSE the implementation only builds on Linux and FreeBSD.
ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-* NetBSD-*-*
# On NetBSD 4.99 after 2007-02, /usr/lib/librefuse provides the FUSE
# interface expected by filesystem implementations and therefore this
# implementation is not needed. This FUSE implementation can also be
# used with the perfuse package on NetBSD.

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
.include "../../filesystems/perfuse/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
