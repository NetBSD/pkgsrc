# $NetBSD: Makefile,v 1.4 2001/10/23 13:15:01 jlam Exp $
#

DISTNAME=		pan-0.10.0.93
CATEGORIES=		news gnome
MASTER_SITES=		http://pan.rebelbase.com/download/0.10.0.93/SOURCE/	\
			${MASTER_SITE_GNOME:=stable/sources/pan/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for Gnome

BUILD_USES_MSGFMT=	YES

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR="${PKGLOCALEDIR}"
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../mk/x11.buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
