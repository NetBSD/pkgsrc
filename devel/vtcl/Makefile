# $NetBSD: Makefile,v 1.3 2006/03/04 21:29:30 jlam Exp $

DISTNAME=		vtcl-1.6.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vtcl/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vtcl.sourceforge.net/
COMMENT=		Visual Tcl/Tk application development environment

HAS_CONFIGURE=		yes
NO_BUILD=		yes

VTCLDIR=		${PREFIX}/lib/vtcl
VTCLDOCDIR=		${PREFIX}/share/doc/vtcl
VTCLEGDIR=		${PREFIX}/share/examples/vtcl

CONFIGURE_ARGS+=	--libdir ${VTCLDIR}

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${VTCLDIR}
	${INSTALL_SCRIPT_DIR} ${VTCLDOCDIR}
	${INSTALL_SCRIPT_DIR} ${VTCLEGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl.tcl ${VTCLDIR}
	cd ${WRKSRC} && ${PAX} -rwpam lib ${VTCLDIR}
	cd ${WRKSRC} && ${PAX} -rwpam images ${VTCLDIR}
	cd ${WRKSRC} && ${PAX} -rwpam doc ${VTCLDOCDIR}
	cd ${WRKSRC} && ${PAX} -rwpam demo ${VTCLEGDIR}
	cd ${WRKSRC} && ${PAX} -rwpam sample ${VTCLEGDIR}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
