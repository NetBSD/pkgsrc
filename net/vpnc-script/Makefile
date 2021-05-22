# $NetBSD: Makefile,v 1.8 2021/05/22 09:12:05 schmonz Exp $

DISTNAME=	vpnc-script-20210401
CATEGORIES=	net security
MASTER_SITES=	http://git.infradead.org/users/dwmw2/vpnc-scripts.git/blob_plain/8fff06090ed193c4a7285e9a10b42e6679e8ecf3:/
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
