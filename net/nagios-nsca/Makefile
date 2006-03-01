# $NetBSD: Makefile,v 1.2 2006/03/01 22:43:04 wiz Exp $
#

DISTNAME=	nsca-2.5
PKGNAME=	nagios-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nagios.org/
COMMENT=	Remote/passive network service for nagios

EGDIR=		${PREFIX}/share/examples/nagios
EGFILES=	nsca.cfg

USE_TOOLS+=	perl

.for files in ${EGFILES}
CONF_FILES+=    ${EGDIR}/${files} ${PKG_SYSCONFDIR}/${files}
.endfor

.include "../../net/nagios-base/Makefile.common"

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nsca ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/send_nsca ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-config/nsca.cfg ${EGDIR}

.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
