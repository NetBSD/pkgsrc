# $NetBSD: Makefile,v 1.2 2002/10/30 03:09:37 rh Exp $
#

DISTNAME=		gtkspell-2.0.2
CATEGORIES=		textproc devel
MASTER_SITES=		http://gtkspell.sourceforge.net/download/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://gtkspell.sourceforge.net/
COMMENT=		Spell checking GtkTextView widget

BUILDLINK_DEPMETHOD.ltdl=	build

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gtkspell-2.0.pc.in

.include "../../textproc/libpspell/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
