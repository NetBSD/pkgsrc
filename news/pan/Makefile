# $NetBSD: Makefile,v 1.9 2002/09/23 23:56:28 jlam Exp $
#

DISTNAME=	pan-0.11.2
PKGREVISION=	2
CATEGORIES=	news gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/pan/} \
		http://pan.rebelbase.com/download/${DISTNAME:C/pan-//}/SOURCE/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://pan.rebelbase.com/
COMMENT=	Newsreader for Gnome

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR="${PKGLOCALEDIR}"
LIBS=			-lcompat

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
