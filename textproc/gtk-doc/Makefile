# $NetBSD: Makefile,v 1.7 2004/02/11 13:41:46 jmmv Exp $
#

DISTNAME=	gtk-doc-1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/1.0/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.gtk.org/rdp/
COMMENT=	Tools for authors of the GTK+ reference documentation

DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
PKGCONFIG_OVERRIDE=	${WRKSRC}/gtk-doc.pc.in

.include "../../lang/perl5/buildlink2.mk"
.include "../../textproc/jade/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
