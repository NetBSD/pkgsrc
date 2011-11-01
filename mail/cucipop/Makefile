# $NetBSD: Makefile,v 1.34 2011/11/01 14:47:09 bsiegert Exp $
#

DISTNAME=	cucipop-1.31
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/cucipop/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	cucipop-1.31-v6-20010223.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The Cubic Circle POP3 mail server
LICENSE=	cucipop-license

PKG_DESTDIR_SUPPORT=	user-destdir

REQD_DIRS+=	${PREFIX}/share/cucipop/bulletins

# cucipop(8) needs to be able to create dotlocks in the mail spool
# directory.  The appropriate permissions should be set on sbin/cucipop
# so that it can do this.
#
SPECIAL_PERMS+=	${PREFIX}/sbin/cucipop ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 2555

# XXX TODO:
# XXX
# XXX (1) sbin/cucipop doesn't need to be setid anything if the mail spool
# XXX     is world-writable.
# XXX (2) Needs to honor ${PKG_SYSCONFDIR} for location of vpop.db.
# XXX     It currently looks in SENDMAILLIB == /etc/mail.
# XXX (3) It needs to use _PATH_MAILDIR from <paths.h> if available
# XXX     instead of hardcoding /var/mail.
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.cucipop
PKG_SUPPORTED_OPTIONS=	db inet6

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if ${OPSYS} != "MirBSD"
LIBS+=		-lcrypt
.endif

.if !empty(PKG_OPTIONS:Mdb)
BDB_ACCEPTED=	db2
CFLAGS+=	-DUSE_DB
LIBS+=		${BDB_LIBS}
.  include "../../mk/bdb.buildlink3.mk"
.endif

MAKE_ENV+=	LIBS=${LIBS:Q}

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=	CFLAGS_INET6=-DINET6
.endif

LDFLAGS.SunOS+=	-lnsl -lsocket

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_MESSAGE.prefix=	Fixing prefix definitions.
SUBST_FILES.prefix=	cucipop.8 makevpopdb.8
SUBST_SED.prefix=	-e "s|@prefix@|${PREFIX}|g"

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cucipop ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/makevpopdb ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/cucipop.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/makevpopdb.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
