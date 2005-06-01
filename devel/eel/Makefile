# $NetBSD: Makefile,v 1.25 2005/06/01 18:02:43 jlam Exp $

DISTNAME=	eel-1.0.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/eel/1.0/}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.eazel.com/
COMMENT=	Eazel Extensions Library

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
