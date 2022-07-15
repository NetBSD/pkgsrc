# $NetBSD: Makefile,v 1.54 2022/07/15 12:37:55 micha Exp $

DISTNAME=		leafnode-1.12.0
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=leafnode/}

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		https://leafnode.sourceforge.io/
COMMENT=		NNTP server for small (dialup) sites
LICENSE=		mit AND gnu-gpl-v2 AND gnu-lgpl-v2.1

CONFLICTS+=		cyrus-imapd<2.2.10nb2

USE_FEATURES=		snprintf vsnprintf

LEAFNODE_SPOOL?=	/var/spool/leafnode
LEAFNODE_LOCKDIR?=	/var/spool/lock/leafnode
LEAFNODE_CONFDIR?=	${PKG_SYSCONFDIR}/leafnode

# Configure INSTALL.pkgsrc (formerly displayed as MESSAGE)
SUBST_CLASSES+=		install
SUBST_STAGE.install=	post-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	${WRKDIR}/INSTALL.pkgsrc
SUBST_VARS.install=	PREFIX
SUBST_VARS.install+=	LEAFNODE_CONFDIR

# Default data dir, login and group are the same as used by inn
BUILD_DEFS+=		LEAFNODE_DATA_DIR INN_DATA_DIR
PKG_GROUPS=		${LEAFNODE_GROUP}
PKG_USERS=		${LEAFNODE_USER}:${LEAFNODE_GROUP}
LEAFNODE_HOME?=		${INN_DATA_DIR}

PKG_GECOS.${LEAFNODE_USER}=	Internet News
PKG_HOME.${LEAFNODE_USER}=	${LEAFNODE_DATA_DIR}
PKG_SHELL.${LEAFNODE_USER}=	${SH}

PKG_GROUPS_VARS+=	LEAFNODE_GROUP
PKG_USERS_VARS+=	LEAFNODE_USER

FILES_SUBST+=		LEAFNODE_SPOOL=${LEAFNODE_SPOOL:Q}
FILES_SUBST+=		LEAFNODE_CONFDIR=${LEAFNODE_CONFDIR:Q}
FILES_SUBST+=		LEAFNODE_LOCKDIR=${LEAFNODE_LOCKDIR:Q}
FILES_SUBST+=		LEAFNODE_HOME=${LEAFNODE_HOME:Q}
MESSAGE_SUBST+=		LEAFNODE_CONFDIR=${LEAFNODE_CONFDIR}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-spooldir=${LEAFNODE_SPOOL:Q}
CONFIGURE_ARGS+=	--with-lockfile=${LEAFNODE_LOCKDIR}/fetchnews.lck
CONFIGURE_ARGS+=	--sysconfdir=${LEAFNODE_CONFDIR:Q}
CONFIGURE_ARGS+=	--with-user=${LEAFNODE_USER:Q}
CONFIGURE_ARGS+=	--with-group=${LEAFNODE_GROUP:Q}
USE_TOOLS+=		gmake

.include "options.mk"

TEST_TARGET=		check

INSTALLATION_DIRS+=	share/examples/leafnode
INSTALLATION_DIRS+=	share/doc/leafnode

pre-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.example 			\
		${DESTDIR}${PREFIX}/share/examples/leafnode
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README-FQDN 		\
		${WRKSRC}/README-MAINTAINER				\
		${WRKSRC}/UNINSTALL-daemontools				\
		${DESTDIR}${PREFIX}/share/doc/leafnode
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc			\
		${DESTDIR}${PREFIX}/share/doc/leafnode/INSTALL.pkgsrc

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
