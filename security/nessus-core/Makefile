# $NetBSD: Makefile,v 1.28 2006/02/05 23:10:45 joerg Exp $

.include 	"../../security/nessus/Makefile.common"

DISTNAME=	nessus-core-${VERS}
PKGREVISION=	1

COMMENT=	Core module of the Nessus Network Security Scanner

WRKSRC=		${WRKDIR}/nessus-core
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk --with-x --localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		ac_cv_path_GTKCONFIG="pkg-config gtk+-2.0" \
			ac_cv_path_GLIBCONFIG="pkg-config glib-2.0"

RCD_SCRIPTS=	nessusd
PLIST_SUBST+=	VARBASE=${VARBASE:Q}

.include "../../security/libnasl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
