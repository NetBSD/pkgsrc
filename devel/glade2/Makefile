# $NetBSD: Makefile,v 1.5 2003/02/18 14:55:57 jmmv Exp $
#

DISTNAME=		glade-1.1.2
PKGNAME=		${DISTNAME:S/-/2-/}
PKGREVISION=		2
CATEGORIES=		devel gnome
MASTER_SITES=		http://glade.pn.org/				\
			${MASTER_SITE_GNOME:=sources/glade/1.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://glade.pn.org/
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
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../databases/gnome-db/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
