# $NetBSD: Makefile,v 1.8 2002/09/10 16:06:48 wiz Exp $
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

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR="${PKGLOCALEDIR}"
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1
LIBS=			-lcompat

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
