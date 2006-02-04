# $NetBSD: Makefile,v 1.28 2006/02/04 15:22:06 adrianp Exp $

DISTNAME=	ircd-hybrid-7.2.0
EXTRACT_SUFX=	.tgz
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ircd-hybrid/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://ircd-hybrid.com/
COMMENT=	IRC server with many options

CONFLICTS+=	ircu-[0-9]*

GNU_CONFIGURE=	YES
BUILD_DEFS+=	IRCD_HYBRID_SYSLOG_FACILITY IRCD_HYBRID_NICLEN \
		IRCD_HYBRID_TOPICLEN IRCD_HYBRID_MAXCONN \
		IRCD_HYBRID_SYSLOG_EVENTS IRCD_HYBRID_IRC_USER \
		IRCD_HYBRID_IRC_GROUP

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	ircd-hybrid
HYBRID_EG=		${PREFIX}/share/examples/ircd-hybrid
HYBRID_DOC=		${PREFIX}/share/doc/ircd-hybrid
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
RCD_SCRIPTS=		ircd-hybrid

CONF_FILES_PERMS=	${HYBRID_EG}/example.conf ${PKG_SYSCONFDIR}/ircd.conf \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0640
OWN_DIRS_PERMS+=	${VARBASE}/log/ircd-hybrid \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770
OWN_DIRS_PERMS+=	${VARBASE}/log/ircd-hybrid/logs \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770
OWN_DIRS_PERMS+=	${VARBASE}/run/ircd-hybrid \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770

FILES_SUBST+=		IRCD_HYBRID_IRC_USER=${IRCD_HYBRID_IRC_USER:Q}
FILES_SUBST+=		IRCD_HYBRID_IRC_GROUP=${IRCD_HYBRID_IRC_GROUP:Q}
FILES_SUBST+=		VARBASE=${VARBASE:Q}

PKG_USERS=		${IRCD_HYBRID_IRC_USER}:${IRCD_HYBRID_IRC_GROUP}::ircd-hybrid\ User::${NOLOGIN}
PKG_GROUPS=		${IRCD_HYBRID_IRC_GROUP}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	etc/example.conf etc/example.efnet.conf \
			etc/example.conf.quick doc/ircd.8
SUBST_SED.paths=	-e "s|/usr/local/ircd/etc|${PKG_SYSCONFDIR}|g" \
			-e "s|/usr/local/ircd/bin|${PREFIX}/bin|g" \
			-e "s|/usr/local/ircd/modules|${PREFIX}/lib/ircd-hybrid/modules|g" \
			-e "s|/usr/share/ircd|${PKG_SYSCONFDIR}|g" \
			-e "s|/var/log|${VARBASE}/log/ircd-hybrid/logs|g"

SUBST_CLASSES+=		bpaths
SUBST_MESSAGE.bpaths=	Fixing hardcoded build paths.
SUBST_STAGE.bpaths=	post-configure
SUBST_FILES.bpaths=	include/defaults.h
SUBST_SED.bpaths=	-e "s|etc|etc/ircd-hybrid|g" \
			-e "s|modules|lib/ircd-hybrid/modules|g" \
			-e "s|IRCD_PREFIX \"/logs\"|\"${VARBASE}/log/ircd-hybrid/logs\"|g" \
			-e "s|ETCPATH \"/ircd.pid\"|\"${VARBASE}/run/ircd-hybrid/ircd.pid\"|g" \
			-e "s|messages|share/ircd-hybrid/messages|g"

CONFIGURE_ARGS+=	--with-nicklen=${IRCD_HYBRID_NICLEN:Q}
CONFIGURE_ARGS+=	--with-topiclen=${IRCD_HYBRID_TOPICLEN:Q}
CONFIGURE_ARGS+=	--enable-syslog=${IRCD_HYBRID_SYSLOG_EVENTS:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/log/ircd-hybrid
CONFIGURE_ARGS+=	--enable-clobber

.if defined(IRCD_HYBRID_SYSLOG_EVENTS) && !empty(IRCD_HYBRID_SYSLOG_EVENTS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-syslog-facility=${IRCD_HYBRID_SYSLOG_FACILITY:Q}
.endif

.if defined(IRCD_HYBRID_MAXCONN) && !empty(IRCD_HYBRID_MAXCONN:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-maxconn=${IRCD_HYBRID_MAXCONN:Q}
.endif

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${HYBRID_EG}
	${INSTALL_DATA_DIR} ${HYBRID_DOC}
	${INSTALL_DATA_DIR} ${HYBRID_DOC}/doc
	${INSTALL_DATA_DIR} ${PREFIX}/share/ircd-hybrid
	${INSTALL_DATA_DIR} ${PREFIX}/share/ircd-hybrid/messages

	${INSTALL_DATA} ${WRKSRC}/etc/example.conf ${HYBRID_EG}
	${INSTALL_DATA} ${WRKSRC}/etc/example.efnet.conf ${HYBRID_EG}
	${INSTALL_DATA} ${WRKSRC}/etc/example.conf.quick ${HYBRID_EG}
	${INSTALL_DATA} ${WRKSRC}/etc/simple.conf ${HYBRID_EG}

	${INSTALL_DATA} ${WRKSRC}/BUGS ${HYBRID_DOC}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${HYBRID_DOC}
	${INSTALL_DATA} ${WRKSRC}/README.FIRST ${HYBRID_DOC}
	${INSTALL_DATA} ${WRKSRC}/README.PLATFORMS ${HYBRID_DOC}
	${INSTALL_DATA} ${WRKSRC}/RELNOTES ${HYBRID_DOC}
	${INSTALL_DATA} ${WRKSRC}/messages/README \
		${HYBRID_DOC}/README.messages
	${INSTALL_DATA} ${WRKSRC}/tools/README.mkpasswd \
		${HYBRID_DOC}/README.ircd-hybrid-mkpasswd

	@${RM} ${WRKSRC}/doc/Makefile
	@${RM} ${WRKSRC}/doc/Makefile.in
	cd ${WRKSRC}/doc && ${PAX} -rwppm . ${HYBRID_DOC}/doc

	cd ${WRKSRC}/messages && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} install

	${INSTALL_PROGRAM} ${WRKSRC}/tools/encspeed \
		${PREFIX}/bin/encspeed
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkpasswd \
		${PREFIX}/bin/ircd-hybrid-mkpasswd

.include "../../mk/bsd.pkg.mk"
