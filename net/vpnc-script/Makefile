# $NetBSD: Makefile,v 1.2 2016/05/17 10:32:08 fhajny Exp $

DISTNAME=	vpnc-script-20140805
PKGREVISION=	1
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
