# $NetBSD: Makefile,v 1.6 2002/09/11 23:39:27 wiz Exp $

DISTNAME=	gabber-0.8.7
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gabber/}

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://gabber.sourceforge.net/
COMMENT=	Gnome Jabber Client

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-xmms

GCC_VERSION!=           gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
# "egcs" cannot be used, as this package tickles c++ compiler bugs
.include "../../lang/gcc/Makefile.gcc"
.endif

.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/libsigc++/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../x11/gnome--/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
