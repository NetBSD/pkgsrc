# $NetBSD: Makefile,v 1.12 2003/09/11 12:23:03 jmmv Exp $
#

DISTNAME=		glade-2.0.0
PKGNAME=		${DISTNAME:S/-/2-/}
PKGREVISION=		3
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glade/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://glade.gnome.org/
COMMENT=		User interface builder for the GTK2+ toolkit and GNOME2

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../databases/libgnomedb/buildlink2.mk"
.include "../../devel/gail/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
