# $NetBSD: Makefile,v 1.1.1.1 2005/06/28 12:43:57 peter Exp $

DISTNAME=		spamd-20050624
CATEGORIES=		mail
MASTER_SITES=		http://nedbsd.nl/~ppostma/pf/

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://www.benzedrine.cx/relaydb.html
COMMENT=		OpenBSD spam deferral daemon

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*

USE_PKGINSTALL=		yes
NO_CONFIGURE=		yes

PKG_USERS=		_spamd:_spamd::Spam\\ Daemon:${VARBASE}/chroot/spamd:/sbin/nologin
PKG_GROUPS=		_spamd

OWN_DIRS=		${VARBASE}/chroot/spamd
RCD_SCRIPTS=            pfspamd

CONF_FILES=		${PREFIX}/share/examples/spamd/spamd.conf \
			    ${PKG_SYSCONFDIR}/spamd.conf

SUBST_CLASSES=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	spamd/spamd.8
SUBST_FILES.fix+=	spamd-setup/spamd-setup.c spamd-setup/spamd-setup.8
SUBST_SED.fix=		-e 's,/etc/spamd.conf,${PKG_SYSCONFDIR}/spamd.conf,g'
SUBST_MESSAGE.fix=	"Fixing configuration paths."

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/spamd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/spamd.conf.cat5 ${PREFIX}/man/cat5/spamd.conf.0
	${INSTALL_MAN} ${WRKSRC}/spamd/spamd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamd/spamd.cat8 ${PREFIX}/man/cat8/spamd.0
	${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.cat8 ${PREFIX}/man/cat8/spamd-setup.0
	${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.cat8 ${PREFIX}/man/cat8/spamdb.0
	${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.cat8 ${PREFIX}/man/cat8/spamlogd.0

	${INSTALL_PROGRAM} ${WRKSRC}/spamd-setup/spamd-setup ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamdb/spamdb ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/spamlogd/spamlogd ${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/spamd
	${INSTALL_DATA} ${WRKSRC}/etc/spamd.conf ${PREFIX}/share/examples/spamd

.include "../../security/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
