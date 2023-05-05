# $NetBSD: Makefile,v 1.11 2023/05/05 13:20:56 schmonz Exp $

DISTNAME=	vpnc-script-20230103
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_GITLAB:=openconnect/vpnc-scripts/-/raw/22756827/}
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	vpnc-script

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.infradead.org/openconnect/vpnc-script.html
COMMENT=	Improved config script for OpenConnect and vpnc
LICENSE=	gnu-gpl-v2

NO_BUILD=	YES
WRKSRC=		${WRKDIR}

EGDIR=			${PREFIX}/share/examples/vpnc-script
INSTALLATION_DIRS=	${EGDIR}
CONF_FILES_PERMS=	${EGDIR}/vpnc-script \
				${PKG_SYSCONFDIR}/vpnc-script \
				${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 555

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
