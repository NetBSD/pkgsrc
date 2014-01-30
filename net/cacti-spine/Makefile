# $NetBSD: Makefile,v 1.2 2014/01/30 16:01:27 pettai Exp $
#

DISTNAME=	cacti-spine-0.8.8b
CATEGORIES=	net
MASTER_SITES=	http://www.cacti.net/downloads/spine/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.cacti.net/spine_info.php
COMMENT=	Spine is a poller for Cacti for large installations
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	cacti>=0.8.7:../../net/cacti

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS=	--with-snmp=${BUILDLINK_PREFIX.net-snmp}

DOCDIR=			share/doc/cacti-spine
EXAMPLES_DIR=		examples
EGDIR=			${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
CONF_FILES=		${EGDIR}/spine.conf.dist ${PKG_SYSCONFDIR}/spine.conf
INSTALLATION_DIRS=	${DOCDIR}

INSTALL_MAKE_FLAGS+=	configdir=${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE* ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/mysql.buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
