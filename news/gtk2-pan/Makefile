# $NetBSD: Makefile,v 1.1.1.1 2002/10/02 03:10:19 rh Exp $
#

DISTNAME=		pan-0.13.0
CATEGORIES=		news
MASTER_SITES=		http://pan.rebelbase.com/download/releases/${DISTNAME:C/pan-//}/SOURCE/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2

BUILD_USES_MSGFMT=	YES

USE_PERL5=		build
USE_X11=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR="${PKGLOCALEDIR}"
LIBS=			-lcompat

.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/gtkspell/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CC=			${PREFIX}/bin/ptlgcc
.include "../../devel/ptl2/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
