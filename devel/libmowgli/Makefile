# $NetBSD: Makefile,v 1.5 2012/10/31 11:17:18 asau Exp $
#

DISTNAME=	libmowgli-0.7.1
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/ \
		http://mirror.billymays.us/libmowgli/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.atheme.org/projects/mowgli
COMMENT=	Development framework for C (like GLib)

PREV_PKGPATH=	devel/mowgli

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmowgli.pc.in

.include "../../mk/bsd.pkg.mk"
