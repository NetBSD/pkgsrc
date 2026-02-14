# $NetBSD: Makefile,v 1.36 2026/02/14 08:27:36 wiz Exp $

DISTNAME=	TkPasMan-2.2a
PKGNAME=	${DISTNAME:S/TkPasMan/tkpasman/}
PKGREVISION=	21
CATEGORIES=	security
MASTER_SITES=	https://wbsoft.home.xs4all.nl/linux/projects/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wbsoft.home.xs4all.nl/linux/tkpasman.html
COMMENT=	Username and password manager that uses the Tk toolkit

CONFIG_SUBST=		PREFIX="${PREFIX}"
CONFIG_SUBST+=		SHELL="${SH}"
CONFIG_SUBST+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIG_SUBST+=		TCLSH="${BUILDLINK_PREFIX.tcl}/bin/tclsh"
CONFIG_SUBST+=		WISH="${BUILDLINK_PREFIX.tk}/bin/wish"
CONFIG_SUBST_SED=	${CONFIG_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

.include "options.mk"

BUILD_TARGET=		tkpasman
INSTALLATION_DIRS=	bin share/doc/tkpasman

post-extract:
	${MV} ${WRKSRC}/config ${WRKSRC}/config.in

do-configure:
	${SED} ${CONFIG_SUBST_SED} ${WRKSRC}/config.in > ${WRKSRC}/config

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkpasman ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/tkpasman

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
