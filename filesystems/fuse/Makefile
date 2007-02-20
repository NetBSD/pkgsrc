# $NetBSD: Makefile,v 1.1.1.1 2007/02/20 23:48:30 xtraeme Exp $
#

DISTNAME=		fuse-2.5.2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://fuse.sourceforge.net/
COMMENT=		Filesystem in Userspace

GNU_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

.include "../../mk/bsd.pkg.mk"
