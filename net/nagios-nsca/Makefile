# $NetBSD: Makefile,v 1.6 2007/11/26 22:14:23 seb Exp $
#

DISTNAME=	nsca-2.6
PKGNAME=	nagios-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nagios.org/
COMMENT=	Remote/passive network service for nagios

EGDIR=		${PREFIX}/share/examples/nagios
EGFILES=	nsca.cfg

USE_TOOLS+=	perl

.for files in ${EGFILES}
CONF_FILES+=	${EGDIR}/${files} ${PKG_SYSCONFDIR}/${files}
.endfor

.include "../../net/nagios-base/Makefile.common"

CONFIGURE_ARGS+=	--with-nsca-user=${NAGIOS_USER:Q}
CONFIGURE_ARGS+=	--with-nsca-grp=${NAGIOS_GROUP:Q}

PKG_GROUPS+=			${NAGIOS_GROUP}
PKG_USERS+=			${NAGIOS_USER}:${NAGIOS_GROUP}
PKG_GECOS.${NAGIOS_USER}=	Nagios Runtime User

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nsca ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/send_nsca ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-config/nsca.cfg ${EGDIR}

.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
