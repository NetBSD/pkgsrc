# $NetBSD: Makefile,v 1.3 2013/10/23 12:50:02 obache Exp $
#

DISTNAME=	ibus-libthai-0.1.0
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/ \
		ftp://linux.thai.net/pub/ThaiLinux/software/libthai/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/ibus-libthai
COMMENT=	Thai imput method engine for IBus based on libthai library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libthai+=	libthai>=0.1.19
.include "../../devel/libthai/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
