# $NetBSD: Makefile,v 1.23 2005/12/05 20:50:57 rillig Exp $

.include 	"../../security/nessus/Makefile.common"

DISTNAME=	nessus-core-${VERS}

COMMENT=	Core module of the Nessus Network Security Scanner

WRKSRC=		${WRKDIR}/nessus-core
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk --with-x --localstatedir=${VARBASE}
CONFIGURE_ENV+=		ac_cv_path_GTKCONFIG="pkg-config gtk+-2.0" \
			ac_cv_path_GLIBCONFIG="pkg-config glib-2.0"

RCD_SCRIPTS=	nessusd
PLIST_SUBST+=	VARBASE=${VARBASE:Q}

.include "../../security/libnasl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
