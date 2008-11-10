# $NetBSD: Makefile,v 1.2 2008/11/10 12:08:17 wiz Exp $
#

DISTNAME=	libmowgli-0.7.0
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://atheme.org/projects/mowgli.shtml
COMMENT=	Development framework for C (like GLib)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmowgli.pc.in

.include "../../mk/bsd.pkg.mk"
