# $NetBSD: Makefile,v 1.66 2018/04/16 14:35:07 wiz Exp $
#

DISTNAME=	gpass-0.4.4
PKGREVISION=	54
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpass/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gpass.sourceforge.net/
COMMENT=	GNOME Password Manager

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
