# $NetBSD: Makefile,v 1.6 2005/12/05 20:51:03 rillig Exp $

DISTNAME=	gdome2-0.8.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gdome2.cs.unibo.it/tarball/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gdome2.cs.unibo.it/
COMMENT=	Gnome DOM (Document Object Model) engine

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
PKGCONFIG_OVERRIDE=	${WRKSRC}/gdome2.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
