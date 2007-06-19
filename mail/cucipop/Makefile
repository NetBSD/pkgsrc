# $NetBSD: Makefile,v 1.29 2007/06/19 21:07:42 jlam Exp $
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

REQD_DIRS+=	${PREFIX}/share/cucipop/bulletins

# cucipop(8) needs to be able to create dotlocks in the mail spool
# directory.  The appropriate permissions should be set on sbin/cucipop
# so that it can do this.
#
SPECIAL_PERMS+=	${PREFIX}/sbin/cucipop ${ROOT_USER} ${ROOT_GROUP} 2555

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

.if !empty(PKG_OPTIONS:Mdb)
BDB_ACCEPTED=	db2
CFLAGS+=	-DUSE_DB
MAKE_ENV+=	LIBS=${BDB_LIBS:Q}
.  include "../../mk/bdb.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=	CFLAGS_INET6=-DINET6
.endif

LDFLAGS.SunOS+=	-lnsl -lsocket

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin
pre-configure:
	@(cd ${WRKSRC};							\
	for f in config.h cucipop.8 makevpopdb.8; do			\
		${SED} -e 's|@prefix@|${PREFIX}|g' $$f > $$f.fixed &&	\
		${MV} $$f.fixed $$f;					\
	done)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cucipop ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/makevpopdb ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/cucipop.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/makevpopdb.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
