# $NetBSD: Makefile,v 1.12 2004/02/09 18:26:06 minskim Exp $
#

DISTNAME=		gtkspell-2.0.5
CATEGORIES=		textproc devel
MASTER_SITES=		http://gtkspell.sourceforge.net/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkspell.sourceforge.net/
COMMENT=		Spell checking GtkTextView widget

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gtkspell-2.0.pc.in

SUBST_CLASSES+=		subdir
SUBST_MESSAGE.subdir=	"Excluding unnecessary subdirs."
SUBST_STAGE.subdir=	post-patch
SUBST_FILES.subdir=	Makefile.in
SUBST_SED.subdir=	-e 's|SUBDIRS = gtkspell examples docs|SUBDIRS = gtkspell|'

.include "../../textproc/aspell/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
