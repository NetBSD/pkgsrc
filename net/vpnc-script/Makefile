# $NetBSD: Makefile,v 1.3 2016/10/28 10:01:51 wiz Exp $

DISTNAME=	vpnc-script-20160828
CATEGORIES=	net security
MASTER_SITES=	http://git.infradead.org/users/dwmw2/vpnc-scripts.git/blob_plain/HEAD:/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	vpnc-script

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.infradead.org/openconnect/vpnc-script.html
# see also http://git.infradead.org/users/dwmw2/vpnc-scripts.git
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
