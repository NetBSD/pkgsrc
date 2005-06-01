# $NetBSD: Makefile,v 1.21 2005/06/01 18:03:21 jlam Exp $

.include 	"../nessus/Makefile.common"

DISTNAME=	nessus-core-${VERS}

COMMENT=	Core module of the Nessus Network Security Scanner

WRKSRC=		${WRKDIR}/nessus-core
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk --with-x --localstatedir=${VARBASE}
CONFIGURE_ENV+=		ac_cv_path_GTKCONFIG="pkg-config gtk+-2.0" \
			ac_cv_path_GLIBCONFIG="pkg-config glib-2.0"

RCD_SCRIPTS=	nessusd

.include "../../security/libnasl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
