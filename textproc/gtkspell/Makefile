# $NetBSD: Makefile,v 1.27 2006/02/05 23:11:02 joerg Exp $

DISTNAME=	gtkspell-2.0.11
PKGREVISION=	2
CATEGORIES=	textproc devel
MASTER_SITES=	http://gtkspell.sourceforge.net/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtkspell.sourceforge.net/
COMMENT=	Spell checking GtkTextView widget

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	gtkspell-2.0.pc.in

SUBST_CLASSES+=		subdir
SUBST_MESSAGE.subdir=	"Excluding unnecessary subdirs."
SUBST_STAGE.subdir=	post-patch
SUBST_FILES.subdir=	Makefile.in
SUBST_SED.subdir=	-e 's|SUBDIRS = gtkspell examples docs|SUBDIRS = gtkspell|'

.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
