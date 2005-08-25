# $NetBSD: Makefile,v 1.1.1.1 2005/08/25 11:14:25 xtraeme Exp $
#

DISTNAME=	dialog
PKGNAME=	cdialog-1.0.20050306
CATEGORIES=	misc
MASTER_SITES=	ftp://invisible-island.net/dialog/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://invisible-island.net/dialog/
COMMENT=	Enhanced version of dialog

WRKSRC=		${WRKDIR}/dialog-1.0-20050306
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

MAKEFILE=	makefile

CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-widec
CONFIGURE_ARGS+=	--with-libtool

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
