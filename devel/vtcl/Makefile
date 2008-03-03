# $NetBSD: Makefile,v 1.4 2008/03/03 17:45:38 jlam Exp $

DISTNAME=		vtcl-1.6.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vtcl/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vtcl.sourceforge.net/
COMMENT=		Visual Tcl/Tk application development environment

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
NO_BUILD=		yes

VTCLDIR=		${PREFIX}/lib/vtcl
VTCLDOCDIR=		${PREFIX}/share/doc/vtcl
VTCLEGDIR=		${PREFIX}/share/examples/vtcl

CONFIGURE_ARGS+=	--libdir ${VTCLDIR}

do-install:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${VTCLDIR}
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${VTCLDOCDIR}
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${VTCLEGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl.tcl ${DESTDIR}${VTCLDIR}
	cd ${WRKSRC} && ${PAX} -rwpam lib ${DESTDIR}${VTCLDIR}
	cd ${WRKSRC} && ${PAX} -rwpam images ${DESTDIR}${VTCLDIR}
	cd ${WRKSRC} && ${PAX} -rwpam doc ${DESTDIR}${VTCLDOCDIR}
	cd ${WRKSRC} && ${PAX} -rwpam demo ${DESTDIR}${VTCLEGDIR}
	cd ${WRKSRC} && ${PAX} -rwpam sample ${DESTDIR}${VTCLEGDIR}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
