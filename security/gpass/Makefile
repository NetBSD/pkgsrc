# $NetBSD: Makefile,v 1.24 2009/07/22 09:01:45 wiz Exp $
#

DISTNAME=	gpass-0.4.4
PKGREVISION=	13
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpass/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gpass.sourceforge.net/
COMMENT=	GNOME Password Manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
