# $NetBSD: Makefile,v 1.52 2014/02/12 23:18:09 tron Exp $

DISTNAME=	prayer-1.3.4
PKGREVISION=	7
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-uxsup.csx.cam.ac.uk/~dpc22/prayer/
COMMENT=	Small, fast, web mail interface
LICENSE=		gnu-gpl-v2

BDB_ACCEPTED=		db4 db5
USE_TOOLS+=		gmake perl
REPLACE_PERL+=		templates/src/build_index.pl
REPLACE_PERL+=		templates/src/build_map_index.pl

PRAYER_USER=		prayer
PRAYER_GROUP=		prayer
PKG_GROUPS=		${PRAYER_GROUP}
PKG_USERS=		${PRAYER_USER}:${PRAYER_GROUP}

PKG_GROUPS_VARS+=	PRAYER_GROUP
PKG_USERS_VARS+=	PRAYER_USER
BUILD_DEFS+=		VARBASE

MAKE_ENV+=	BASECFLAGS=${CFLAGS:Q}
MAKE_ENV+=	BDBBASE="${BDBBASE}"
MAKE_ENV+=	BDB_TYPE="${BDB_TYPE}"
MAKE_ENV+=	BUILDLINK_PREFIX.imap-uw="${BUILDLINK_PREFIX.imap-uw}"
MAKE_ENV+=	BUILDLINK_PREFIX.tidy="${BUILDLINK_PREFIX.tidy}"
MAKE_ENV+=	EGDIR=${EGDIR}
MAKE_ENV+=	KRB5BASE="${KRB5BASE}"
MAKE_ENV+=	KRB5_TYPE=${KRB5_TYPE:Q}
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	PRAYER_USER=${PRAYER_USER} PRAYER_GROUP=${PRAYER_GROUP}
MAKE_ENV+=	ROOT_USER=${ROOT_USER} ROOT_GROUP=${ROOT_GROUP}
MAKE_ENV+=	RO_USER=${ROOT_USER}
MAKE_ENV+=	SSLCERTS=${SSLCERTS:Q}

PKG_SYSCONFSUBDIR=	prayer
EGDIR=			${PREFIX}/share/examples/prayer

RCD_SCRIPTS=		prayer

CONF_FILES=	${EGDIR}/prayer.cf ${PKG_SYSCONFDIR}/prayer.cf
CONF_FILES+=	${EGDIR}/prayer-accountd.cf ${PKG_SYSCONFDIR}/prayer-accountd.cf
CONF_FILES+=	${EGDIR}/motd.html ${PKG_SYSCONFDIR}/motd.html

VAR_PREFIX=	${VARBASE}/spool/prayer

OWN_DIRS_PERMS+=${VAR_PREFIX} ${PRAYER_USER} ${PRAYER_GROUP} 0750

FILES_SUBST+=	OPSYS=${OPSYS}
FILES_SUBST+=	VAR_PREFIX=${VAR_PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rename:-lutil:"-lsocket -lnsl"
BUILDLINK_TRANSFORM+=	rm:-lcom_err # XXX: handle pkgsrc krb
.endif

post-patch:
	${FIND} ${WRKSRC} -name CVS -type d -print | ${SORT} -r | \
		${XARGS} ${RM} -rf
	cp ${WRKSRC}/defaults/Config ${WRKSRC}

INSTALLATION_DIRS+=	${EGDIR}

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mail/imap-uw/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
