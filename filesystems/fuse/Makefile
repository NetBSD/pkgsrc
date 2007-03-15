# $NetBSD: Makefile,v 1.2 2007/03/15 22:55:21 agc Exp $
#

DISTNAME=		fuse-2.5.2
CATEGORIES=		filesystems
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://fuse.sourceforge.net/
COMMENT=		Filesystem in Userspace

GNU_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

.include "../../mk/bsd.pkg.mk"
