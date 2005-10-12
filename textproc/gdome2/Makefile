# $NetBSD: Makefile,v 1.4 2005/10/12 21:22:08 reed Exp $

DISTNAME=	gdome2-0.8.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gdome2.cs.unibo.it/tarball/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gdome2.cs.unibo.it/
COMMENT=	Gnome DOM (Document Object Model) engine

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	${WRKSRC}/gdome2.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
