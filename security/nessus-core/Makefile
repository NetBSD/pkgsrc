# $NetBSD: Makefile,v 1.18 2005/01/11 12:03:26 adam Exp $

DISTNAME=	nessus-core-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Core module of the Nessus Network Security Scanner

WRKSRC=		${WRKDIR}/nessus-core
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk --with-x --localstatedir=${VARBASE}
CONFIGURE_ENV+=		ac_cv_path_GTKCONFIG="pkg-config gtk+-2.0" \
			ac_cv_path_GLIBCONFIG="pkg-config glib-2.0"

RCD_SCRIPTS=	nessusd

.include "../../security/libnasl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
