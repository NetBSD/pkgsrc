# $NetBSD: Makefile,v 1.30 2009/06/30 00:07:23 joerg Exp $
#

DISTNAME=	lavaps-2.7
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/
COMMENT=	Lava lamp of currently running processes

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-tcltk \
		--with-tcl-ver=8.4.18 \
		--with-tk-ver=8.4.18 \
		--with-tcltk-lib-suffix-type=nodot

# prevents the GConf schema from going into / when building the tcl/tk version
MAKE_ENV+=	PKGSRC_INSTALL_SCHEMAS=no

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
