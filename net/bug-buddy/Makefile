# $NetBSD: Makefile,v 1.12 2003/12/14 23:54:09 xtraeme Exp $
#

DISTNAME=		bug-buddy-2.4.0
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/bug-buddy/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Graphical GNOME2 bug reporting tool

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
