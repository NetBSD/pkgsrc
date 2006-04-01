# $NetBSD: Makefile,v 1.8 2006/04/01 12:14:27 peter Exp $

DISTNAME=		spamd-20060330
CATEGORIES=		mail
MASTER_SITES=		http://nedbsd.nl/~ppostma/pf/

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://www.benzedrine.cx/relaydb.html
COMMENT=		OpenBSD spam deferral daemon

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-* FreeBSD-*-* DragonFly-*-*

NO_CONFIGURE=		yes

SPAMD_HOME=		${VARBASE}/chroot/spamd
OWN_DIRS=		${SPAMD_HOME}

CPPFLAGS+=		-DPATH_SPAMD_HOME=\"${SPAMD_HOME}\"
CPPFLAGS+=		-DPATH_SPAMD_DB=\"${VARBASE}/db/spamd\"
CPPFLAGS+=		-DPATH_PFCTL=\"${PFCTL}\"
CPPFLAGS+=		-DPATH_SPAMD_CONF=\"${SPAMD_CONF}\"

PKG_USERS=		_spamd:_spamd::Spam\ Daemon:${SPAMD_HOME}:/sbin/nologin
PKG_GROUPS=		_spamd

RCD_SCRIPTS=            pfspamd

SPAMD_CONF=		${PKG_SYSCONFDIR}/spamd.conf
CONF_FILES=		${PREFIX}/share/examples/spamd/spamd.conf ${SPAMD_CONF}

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	spamd/spamd.8
SUBST_FILES.fix+=	spamd-setup/spamd-setup.8
SUBST_SED.fix=		-e 's,/etc/spamd.conf,${SPAMD_CONF},g'
SUBST_MESSAGE.fix=	Fixing configuration paths.

INSTALLATION_DIRS+=	libexec sbin ${PKGMANDIR}/cat5 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 share/examples/spamd

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/spamd.conf.5 ${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/man/spamd.conf.cat5 ${PREFIX}/${PKGMANDIR}/cat5/spamd.conf.0
	${INSTALL_MAN} ${WRKSRC}/spamd/spamd.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/spamd/spamd.cat8 ${PREFIX}/${PKGMANDIR}/cat8/spamd.0
	${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.cat8 ${PREFIX}/${PKGMANDIR}/cat8/spamd-setup.0
	${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.cat8 ${PREFIX}/${PKGMANDIR}/cat8/spamdb.0
	${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.cat8 ${PREFIX}/${PKGMANDIR}/cat8/spamlogd.0

	${INSTALL_PROGRAM} ${WRKSRC}/spamd-setup/spamd-setup ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamdb/spamdb ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/spamlogd/spamlogd ${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/etc/spamd.conf ${PREFIX}/share/examples/spamd

.include "../../security/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
