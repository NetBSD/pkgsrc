# $NetBSD: Makefile,v 1.7 2002/10/08 22:31:55 jlam Exp $
#

DISTNAME=		linc-0.5.0
PKGREVISION=		1
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.0/sources/linc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		network client/server library

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
