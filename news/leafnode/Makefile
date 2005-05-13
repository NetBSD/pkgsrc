# $NetBSD: Makefile,v 1.24 2005/05/13 15:08:04 kim Exp $

DISTNAME=		leafnode-1.11.2.rel
PKGNAME=		${DISTNAME:S/.rel//}
PKGREVISION=		# empty
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=leafnode/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://leafnode.sourceforge.net/
COMMENT=		NNTP server for small (dialup) sites

CONFLICTS+=		cyrus-imapd<2.2.10nb2

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

LEAFNODE_SPOOL?=	/var/spool/leafnode
LEAFNODE_LOCKDIR?=	/var/spool/lock/leafnode
LEAFNODE_CONFDIR?=	${PKG_SYSCONFDIR}/leafnode

# Default data dir, login and group are the same as used by inn
#
BUILD_DEFS+=		LEAFNODE_DATA_DIR LEAFNODE_GROUP LEAFNODE_USER
PKG_USERS=		${LEAFNODE_USER}:${LEAFNODE_GROUP}::Internet\\ News:${LEAFNODE_DATA_DIR}:${SH}
PKG_GROUPS=		${LEAFNODE_GROUP}
LEAFNODE_HOME?=		${INN_DATA_DIR}

BUILD_DEFS+=		USE_INET6

FILES_SUBST+=		LEAFNODE_SPOOL=${LEAFNODE_SPOOL}
FILES_SUBST+=		LEAFNODE_CONFDIR=${LEAFNODE_CONFDIR}
FILES_SUBST+=		LEAFNODE_LOCKDIR=${LEAFNODE_LOCKDIR}
FILES_SUBST+=		LEAFNODE_HOME=${LEAFNODE_HOME}
MESSAGE_SUBST+=		LEAFNODE_CONFDIR=${LEAFNODE_CONFDIR}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-spooldir=${LEAFNODE_SPOOL}
CONFIGURE_ARGS+=	--with-lockfile=${LEAFNODE_LOCKDIR}/fetchnews.lck
CONFIGURE_ARGS+=	--sysconfdir=${LEAFNODE_CONFDIR}
CONFIGURE_ARGS+=	--with-user=${LEAFNODE_USER}
CONFIGURE_ARGS+=	--with-group=${LEAFNODE_GROUP}
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/leafnode
	${INSTALL_DATA} ${WRKSRC}/config.example 			\
				${PREFIX}/share/examples/leafnode
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/leafnode

	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README-FQDN 		\
			${WRKSRC}/README-MAINTAINER			\
			${WRKSRC}/README-daemontools			\
			${WRKSRC}/README.FIRST ${PREFIX}/share/doc/leafnode

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
