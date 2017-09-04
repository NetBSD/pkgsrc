# $NetBSD: Makefile,v 1.18 2017/09/04 18:00:57 wiz Exp $

DISTNAME=		spamd-20060330
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://nedbsd.nl/~ppostma/pf/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.benzedrine.cx/relaydb.html
COMMENT=		OpenBSD spam deferral daemon

NO_CONFIGURE=		yes

SPAMD_HOME=		${VARBASE}/chroot/spamd
OWN_DIRS=		${SPAMD_HOME}

CPPFLAGS+=		-DPATH_SPAMD_HOME=\"${SPAMD_HOME}\"
CPPFLAGS+=		-DPATH_SPAMD_DB=\"${VARBASE}/db/spamd\"
CPPFLAGS+=		-DPATH_PFCTL=\"${PFCTL}\"
CPPFLAGS+=		-DPATH_SPAMD_CONF=\"${SPAMD_CONF}\"

PKG_GROUPS=		_spamd
PKG_USERS=		_spamd:_spamd
PKG_GECOS._spamd=	Spam Daemon User
PKG_HOME._spamd=	${SPAMD_HOME}

RCD_SCRIPTS=		pfspamd

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
	${INSTALL_MAN} ${WRKSRC}/man/spamd.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/spamd/spamd.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

	${INSTALL_PROGRAM} ${WRKSRC}/spamd-setup/spamd-setup \
		${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd \
		${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamdb/spamdb \
		${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/spamlogd/spamlogd \
		${DESTDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/etc/spamd.conf ${DESTDIR}${PREFIX}/share/examples/spamd

.include "../../mk/pf.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
