# $NetBSD: Makefile,v 1.5 2003/01/03 18:09:45 wiz Exp $
#

DISTNAME=		pan-0.13.3
CATEGORIES=		news
MASTER_SITES=		http://pan.rebelbase.com/download/releases/${DISTNAME:C/pan-//}/SOURCE/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2

BUILD_USES_MSGFMT=	YES

USE_PERL5=		build
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
LIBS=			-lcompat

.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/gtkspell/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
