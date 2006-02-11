# $NetBSD: Makefile,v 1.1.1.1 2006/02/11 13:09:21 rillig Exp $
#

.include "../../graphics/pornview/Makefile.common"

PKGNAME=		${DISTNAME:S/_0.2pre1.orig/-gtk2-0.2.0pre1/}

COMMENT+=		(GTK+ 2.0 interface)

CONFLICTS=		pornview-[0-9]*

USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-gtk2

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
