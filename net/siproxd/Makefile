# $NetBSD: Makefile,v 1.12 2024/05/29 16:34:03 adam Exp $

DISTNAME=	siproxd-0.8.3
#PKGREVISION=	1
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=siproxd/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://siproxd.sourceforge.net/
COMMENT=	Session Initiation Protocol (SIP) Application-Level Gateway
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE

SIPROXD_USER?=		siproxd
SIPROXD_GROUP?=		siproxd
SIPROXD_HOME?=		${VARBASE}/chroot/siproxd

PKG_GROUPS=		${SIPROXD_GROUP}
PKG_USERS=		${SIPROXD_USER}:${SIPROXD_GROUP}

PKG_GECOS.${SIPROXD_USER}=	SIP proxy
PKG_HOME.${SIPROXD_USER}=	${SIPROXD_HOME}

PKG_GROUPS_VARS+=	SIPROXD_GROUP
PKG_USERS_VARS+=	SIPROXD_USER

FILES_SUBST+=		SIPROXD_USER=${SIPROXD_USER:Q}
FILES_SUBST+=		SIPROXD_GROUP=${SIPROXD_GROUP:Q}
FILES_SUBST+=		SIPROXD_HOME=${SIPROXD_HOME:Q}

RCD_SCRIPTS+=		siproxd
PKG_SYSCONFSUBDIR=	siproxd

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libosip-prefix=${BUILDLINK_PREFIX.libosip2}

DOCDIR=			share/doc/siproxd
EGDIR=			share/examples/siproxd

CONF_FILES=		${PREFIX}/${EGDIR}/siproxd.conf.example \
				${PKG_SYSCONFDIR}/siproxd.conf
CONF_FILES+=		${PREFIX}/${EGDIR}/siproxd_passwd.cfg \
				${PKG_SYSCONFDIR}/siproxd_passwd.cfg

OWN_DIRS+=		${SIPROXD_HOME}

INSTALLATION_DIRS=	sbin ${DOCDIR} ${EGDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doc/siproxd.conf.example
SUBST_MESSAGE.paths=	performing pathname substitutions
SUBST_VARS.paths=	VARBASE PREFIX PKG_SYSCONFDIR SIPROXD_USER SIPROXD_HOME

post-install:
.for ff in README RELNOTES doc/FAQ doc/KNOWN_BUGS doc/RFC3261_compliance.txt
	${INSTALL_DATA} ${WRKSRC}/${ff} ${DESTDIR}${PREFIX}/${DOCDIR}/
.endfor
.for ff in sample_asterisk.txt sample_cfg_budgetone.txt sample_cfg_x-lite.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${ff} ${DESTDIR}${PREFIX}/${EGDIR}/
.endfor

.include "../../mk/pthread.buildlink3.mk"
# siproxd's configure does not check for PTHREAD_LDFLAGS
PTHREAD_LIBS+=	${PTHREAD_LDFLAGS}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
