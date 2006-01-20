# $NetBSD: Makefile,v 1.10 2006/01/20 16:15:53 jmmv Exp $
#

DISTNAME=	gpass-0.4.4
PKGREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpass/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gpass.sourceforge.net/
COMMENT=	GNOME Password Manager

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
