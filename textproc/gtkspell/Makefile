# $NetBSD: Makefile,v 1.5 2003/05/02 11:56:30 wiz Exp $
#

DISTNAME=		gtkspell-2.0.2
PKGREVISION=	3
CATEGORIES=		textproc devel
MASTER_SITES=		http://gtkspell.sourceforge.net/download/

MAINTAINER=		packages@netbsd.org
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
