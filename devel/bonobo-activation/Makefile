# $NetBSD: Makefile,v 1.7 2002/09/10 16:06:38 wiz Exp $
#

DISTNAME=		bonobo-activation-1.0.2
PKGREVISION=		1
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
USE_BUILDLINK2=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../devel/ptl2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
