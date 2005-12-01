# $NetBSD: Makefile,v 1.1.1.1 2005/12/01 03:32:03 minskim Exp $
#

DISTNAME=		detox-1.2.0-rc1
PKGNAME=		${DISTNAME:S/-rc/rc}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=detox/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://detox.sourceforge.net/
COMMENT=		Removes non-standard characters from filenames

GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-base install-unsafe-config

USE_PKGINSTALL=		yes
EGDIR=			${PREFIX}/share/examples/detox
CONF_FILES=		${EGDIR}/detoxrc ${PKG_SYSCONFDIR}/detoxrc

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/detoxrc ${EGDIR}/detoxrc

.include "../../mk/bsd.pkg.mk"
