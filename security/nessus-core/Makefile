# $NetBSD: Makefile,v 1.20 2005/04/11 21:47:14 tv Exp $

.include 	"../nessus/Makefile.common"

DISTNAME=	nessus-core-${VERS}

COMMENT=	Core module of the Nessus Network Security Scanner

WRKSRC=		${WRKDIR}/nessus-core
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
