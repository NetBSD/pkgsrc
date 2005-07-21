# $NetBSD: Makefile,v 1.7 2005/07/21 16:29:56 wiz Exp $
#

DISTNAME=	gpass-0.4.4
PKGREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpass/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://gpass.sourceforge.net/
COMMENT=	GNOME Password Manager

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
