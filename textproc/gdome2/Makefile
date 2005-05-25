# $NetBSD: Makefile,v 1.3 2005/05/25 09:27:39 adam Exp $

DISTNAME=	gdome2-0.8.1
CATEGORIES=	games
MASTER_SITES=	http://gdome2.cs.unibo.it/tarball/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gdome2.cs.unibo.it/
COMMENT=	Gnome DOM (Document Object Model) engine

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
PKGCONFIG_OVERRIDE=	${WRKSRC}/gdome2.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
