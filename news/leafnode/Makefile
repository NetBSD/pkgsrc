# $NetBSD: Makefile,v 1.1.1.1 2002/06/16 11:34:26 cjep Exp $

DISTNAME=		leafnode-1.9.22
CATEGORIES=		news
MASTER_SITES=		ftp://wpxx02.toxi.uni-wuerzburg.de/pub/            \
			ftp://ftp.karlsruhe.org/pub/news/servers/leafnode/ \
			ftp://ftp.stikman.com/pub/leafnode/                \
			${MASTER_SITE_SUNSITE:=system/news/transport/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.leafnode.org/
COMMENT=		NNTP server for small (dialup) sites

WRKSRC=			${WRKDIR}/${DISTNAME}.rel

LEAFNODE_SPOOL?=	/var/spool/leafnode
LEAFNODE_LOCKDIR?=	/var/spool/lock/leafnode
LEAFNODE_CONFDIR?=	${PKG_SYSCONFDIR}/leafnode

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

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

MESSAGE_SUBST+=		LEAFNODE_CONFDIR=${LEAFNODE_CONFDIR}

post-build:
	for F in DEINSTALL INSTALL; do					\
	${SED} 	-e 's#@@LEAFNODE_SPOOL@@#${LEAFNODE_SPOOL}#g' 		\
		-e 's#@@LEAFNODE_LOCKDIR@@#${LEAFNODE_LOCKDIR}#g'	\
		-e 's#@@LEAFNODE_CONFDIR@@#${LEAFNODE_CONFDIR}#g'	\
		-e 's#@@PREFIX@@#${PREFIX}#g'	\
		${PKGDIR}/$${F}	> ${WRKDIR}/$${F}; done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/leafnode
	${INSTALL_DATA} ${WRKSRC}/config.example 			\
				${PREFIX}/share/examples/leafnode
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
