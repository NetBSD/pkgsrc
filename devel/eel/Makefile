# $NetBSD: Makefile,v 1.5 2002/10/08 11:56:04 wiz Exp $
#

DISTNAME=		eel-1.0.1
PKGREVISION=		1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/eel/}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		Eazel Extenstions Library

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_PERL5=		YES
USE_GMAKE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/librsvg/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
