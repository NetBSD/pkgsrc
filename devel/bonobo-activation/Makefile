# $NetBSD: Makefile,v 1.1.1.1 2002/04/27 08:57:57 rh Exp $
#

DISTNAME=		bonobo-activation-0.9.7
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=pre-gnome2/sources/bonobo-activation/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		Object activation framework for GNOME2

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc

USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../textproc/libxml2/buildlink.mk"
.include "../../net/ORBit2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
