# $NetBSD: Makefile,v 1.47 2023/01/29 21:16:53 ryoon Exp $

DISTNAME=	gtk-im-libthai-0.2.1
PKGREVISION=	31
CATEGORIES=	inputmethod
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://linux.thai.net/projects/gtk-im-libthai
COMMENT=	GTK+-2.0 Thai Input Module
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

GTK2_IMMODULES=	yes
.include "../../x11/gtk2/modules.mk"
GTK3_IMMODULES=	yes
.include "../../x11/gtk3/modules.mk"

.include "../../devel/libthai/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
