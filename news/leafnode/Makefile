# $NetBSD: Makefile,v 1.14 2004/01/20 12:22:41 agc Exp $

DISTNAME=		leafnode-1.9.49.rel
PKGNAME=		${DISTNAME:S/.rel//}
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=leafnode/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.leafnode.org/
COMMENT=		NNTP server for small (dialup) sites

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

LEAFNODE_SPOOL?=	/var/spool/leafnode
LEAFNODE_LOCKDIR?=	/var/spool/lock/leafnode
LEAFNODE_CONFDIR?=	${PKG_SYSCONFDIR}/leafnode

# Use news login and be compatible with inn package
#
BUILD_DEFS+=		INN_DATA_DIR
PKG_USERS=		news:news::Internet\\ News:${INN_DATA_DIR}:${SH}
PKG_GROUPS=		news
LEAFNODE_HOME?=		${INN_DATA_DIR}

FILES_SUBST+=	LEAFNODE_SPOOL=${LEAFNODE_SPOOL}
FILES_SUBST+=	LEAFNODE_CONFDIR=${LEAFNODE_CONFDIR}
FILES_SUBST+=	LEAFNODE_LOCKDIR=${LEAFNODE_LOCKDIR}
FILES_SUBST+=	LEAFNODE_HOME=${LEAFNODE_HOME}
MESSAGE_SUBST+=		LEAFNODE_CONFDIR=${LEAFNODE_CONFDIR}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-spooldir=${LEAFNODE_SPOOL}
CONFIGURE_ARGS+=	--with-lockfile=${LEAFNODE_LOCKDIR}/fetchnews.lck
CONFIGURE_ARGS+=	--sysconfdir=${LEAFNODE_CONFDIR}
USE_GMAKE=		yes

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

.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
