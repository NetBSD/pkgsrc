# $NetBSD: Makefile,v 1.17 2020/06/02 08:22:57 adam Exp $

DISTNAME=	gdome2-0.8.1
PKGREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	http://gdome2.cs.unibo.it/tarball/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gdome2.cs.unibo.it/
COMMENT=	Gnome DOM (Document Object Model) engine

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-dir=${DESTDIR}${PREFIX}/share/doc/gdome2
PKGCONFIG_OVERRIDE=	${WRKSRC}/gdome2.pc.in

SUBST_CLASSES+=		docdir
SUBST_STAGE.docdir=	pre-configure
SUBST_FILES.docdir=	gtk-doc/Makefile.in
SUBST_SED.docdir=	-e 's,^TARGET_DIR =.*,TARGET_DIR = $$(HTML_DIR),'

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
