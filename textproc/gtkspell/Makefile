# $NetBSD: Makefile,v 1.1.1.1 2002/09/25 04:54:46 rh Exp $
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

.include "../../textproc/libpspell/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
