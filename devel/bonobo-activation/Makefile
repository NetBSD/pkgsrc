# $NetBSD: Makefile,v 1.4 2002/07/12 15:59:44 wiz Exp $
#

DISTNAME=		bonobo-activation-1.0.2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.0/sources/bonobo-activation/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		Object activation framework for GNOME2

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc

USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK_ONLY=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../textproc/libxml2/buildlink.mk"
.include "../../net/ORBit2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
