# $NetBSD: Makefile,v 1.17 2020/03/20 11:57:33 nia Exp $

DISTNAME=		vtcl-1.6.0
PKGREVISION=		9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vtcl/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vtcl.sourceforge.net/
COMMENT=		Visual Tcl/Tk application development environment

USE_TOOLS+=	pax wish:run
HAS_CONFIGURE=	yes
NO_BUILD=	yes

VTCLDIR=		${PREFIX}/lib/vtcl
VTCLDOCDIR=		${PREFIX}/share/doc/vtcl
VTCLEGDIR=		${PREFIX}/share/examples/vtcl

CONFIGURE_ARGS+=	--libdir ${VTCLDIR}
CONFIGURE_ENV+=		WISH=${TOOLS_PATH.wish}

do-install:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${VTCLDIR}
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${VTCLDOCDIR}
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${VTCLEGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl.tcl ${DESTDIR}${VTCLDIR}
	cd ${WRKSRC} && pax -rwpam lib ${DESTDIR}${VTCLDIR}
	cd ${WRKSRC} && pax -rwpam images ${DESTDIR}${VTCLDIR}
	cd ${WRKSRC} && pax -rwpam doc ${DESTDIR}${VTCLDOCDIR}
	cd ${WRKSRC} && pax -rwpam demo ${DESTDIR}${VTCLEGDIR}
	cd ${WRKSRC} && pax -rwpam sample ${DESTDIR}${VTCLEGDIR}

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
