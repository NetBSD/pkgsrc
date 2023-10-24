# $NetBSD: Makefile,v 1.14 2023/10/24 22:10:13 wiz Exp $
#

DISTNAME=	cacti-spine-1.2.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://www.cacti.net/downloads/spine/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.cacti.net/spine_info.php
COMMENT=	Cacti poller for large installations
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	cacti>=1.2.2:../../net/cacti
TOOL_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--with-snmp=${BUILDLINK_PREFIX.net-snmp}

BUILD_DEFS+=		VARBASE
CACTI_LOGDIR?=		${VARBASE}/log/cacti

DOCDIR=			share/doc/cacti-spine
EXAMPLES_DIR=		examples
EGDIR=			${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
CONF_FILES=		${EGDIR}/spine.conf.dist ${PKG_SYSCONFDIR}/spine.conf

INSTALLATION_DIRS=	bin ${DOCDIR} ${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	PKG_SYSCONFDIR CACTI_LOGDIR
SUBST_FILES.paths=	${WRKSRC}/spine.h

INSTALL_MAKE_FLAGS+=	configdir=${EGDIR}

LDFLAGS.SunOS+=		-lm

post-install:
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE* ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/mysql.buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
