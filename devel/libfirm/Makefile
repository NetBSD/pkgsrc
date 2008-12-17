# $NetBSD: Makefile,v 1.2 2008/12/17 16:52:35 joerg Exp $
#

DISTNAME=	libfirm-1.15.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libfirm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libfirm.sourceforge.net/
COMMENT=	Provides a graph-based SSA representation of programs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfirm.pc.in

.if exists(/usr/include/wchar.h)
CONFIGURE_ARGS+=	--enable-wchar-support
.endif

#
# NOTE: jvm support requires dlopen/dlsym
#.include "../../mk/dlopen.buildlink3.mk"
#
.include "../../mk/bsd.pkg.mk"
