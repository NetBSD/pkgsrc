# $NetBSD: Makefile,v 1.2.2.2 2002/08/22 11:10:24 jlam Exp $
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
