# $NetBSD: Makefile,v 1.11 2004/01/03 18:49:54 reed Exp $
#

DISTNAME=		gtkspell-2.0.2
PKGREVISION=		6
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

.include "../../textproc/aspell/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
