# $NetBSD: Makefile,v 1.1.1.1 2006/01/21 08:12:03 agc Exp $

DISTNAME=		vtcl-1.6.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vtcl/}

MAINTAINER=		tech-pkg@NetBSD.org
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
