# $NetBSD: Makefile,v 1.6 2022/06/30 11:18:44 nia Exp $
#

DISTNAME=		tinydyndns-run-20201030
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Configures tinydyndns to serve and update records
LICENSE=		2-clause-bsd

DEPENDS+=		nopop3d-[0-9]*:../../mail/nopop3d
DEPENDS+=		qmail-[0-9]*:../../mail/qmail
DEPENDS+=		tinydyndns-[0-9]*:../../net/tinydyndns
DEPENDS+=		cvm-[0-9]*:../../security/cvm
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
NO_CHECKSUM=		yes

PKG_SYSCONFSUBDIR=	tinydyn
PKG_SYSCONFDIR_PERMS=	${TINYDYN_USER} ${REAL_ROOT_GROUP} 3755

CONF_FILES_MODE=	0600
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/passwd \
			${PKG_SYSCONFDIR}/passwd

PKG_GROUPS=		${DJBDNS_DJBDNS_GROUP}
PKG_USERS+=		${TINYDYN_USER}:${DJBDNS_DJBDNS_GROUP}
RCD_SCRIPTS=		tinydyn tinydyndns tinydynpop3d
FILES_SUBST+=		TINYDYN_USER=${TINYDYN_USER:Q}
FILES_SUBST+=		DJBDNS_LOG_USER=${DJBDNS_LOG_USER:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}
FILES_SUBST+=		CUT=${CUT:Q}

BUILD_DEFS+=		TINYDYN_USER DJBDNS_LOG_USER
BUILD_DEFS+=		DJBDNS_DJBDNS_GROUP

SUBST_CLASSES+=		rcd
SUBST_STAGE.rcd=	pre-configure
SUBST_FILES.rcd=	README.pkgsrc
SUBST_VARS.rcd=		PKG_SYSCONFDIR RCD_SCRIPTS_DIR

SUBST_CLASSES+=		scripts
SUBST_STAGE.scripts=	pre-configure
SUBST_FILES.scripts=	tinydyndns-call-update tinydyndns-make-client
SUBST_FILES.scripts+=	tinydyndns-passwd tinydyndns-pop3d
SUBST_VARS.scripts=	SH PKGNAME ECHO PKG_SYSCONFDIR PREFIX HEAD
SUBST_VARS.scripts+=	ID GREP CAT SED MV CHMOD NOLOGIN
SUBST_VARS.scripts+=	TINYDYN_USER

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON=		tinydyndns-pwhash

INSTALLATION_DIRS=	bin share/doc/${PKGBASE} share/examples/${PKGBASE}

post-extract:
	${CP} ${FILESDIR}/README.pkgsrc ${WRKSRC}/
	for f in tinydyndns-call-update tinydyndns-make-client \
		tinydyndns-passwd tinydyndns-pop3d; do \
		${CP} ${FILESDIR}/$$f.sh ${WRKSRC}/$$f; \
	done
	${CP} ${FILESDIR}/tinydyndns-pwhash.py ${WRKSRC}/tinydyndns-pwhash

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.pkgsrc ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	for f in tinydyndns-call-update tinydyndns-make-client \
		tinydyndns-passwd tinydyndns-pop3d tinydyndns-pwhash; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/bin; \
	done
	${TOUCH} ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/passwd; \
	${CHMOD} 600 ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/passwd

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
