# $NetBSD: Makefile,v 1.26 2003/08/31 00:10:28 chris Exp $
#

DISTNAME=		pan-0.14.1
CATEGORIES=		news
MASTER_SITES=		http://pan.rebelbase.com/download/releases/${DISTNAME:C/pan-//}/SOURCE/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2

DEPENDS+=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	YES

USE_PERL5=		build
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
LIBS=			-lcompat

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../net/gnet/buildlink2.mk"
.include "../../textproc/gtkspell/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
