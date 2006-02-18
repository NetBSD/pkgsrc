# $NetBSD: Makefile,v 1.1.1.1 2006/02/18 17:13:45 bouyer Exp $
#

PKGNAME=	nagios-${DISTNAME}
DISTNAME=	nsca-${NSCAVERSION}
NSCAVERSION=	2.5
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nagios.org/
COMMENT=	Remote/passive network service for nagios

EGDIR=		${PREFIX}/share/examples/nagios
EGFILES=	nsca.cfg

.for files in ${EGFILES}
CONF_FILES+=    ${EGDIR}/${files} ${PKG_SYSCONFDIR}/${files}
.endfor

.include "../../net/nagios-base/Makefile.common"

.include "../../mk/bsd.prefs.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nsca ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/send_nsca ${PREFIX}/bin
	${INSTALL_DATA}    ${WRKSRC}/sample-config/nsca.cfg ${EGDIR}
