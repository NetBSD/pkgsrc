# $NetBSD: Makefile,v 1.33 2006/07/19 19:14:38 jlam Exp $

DISTNAME=	eel-1.0.2
PKGREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/eel/1.0/}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eazel.com/
COMMENT=	Eazel Extensions Library

BROKEN_GETTEXT_DETECTION=	yes

USE_TOOLS+=		gmake msgfmt perl
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
