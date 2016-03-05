# $NetBSD: Makefile,v 1.92 2016/03/05 11:28:49 jperkin Exp $

DISTNAME=		nmh-1.6
PKGREVISION=		5
CATEGORIES=		mail
MASTER_SITES=		http://savannah.nongnu.org/download/nmh/

MAINTAINER=		leot@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/nmh/
COMMENT=		Cleaned up MH mailer suite
LICENSE=		modified-bsd

CONFLICTS=		ja-mh-[0-9]*
CONFLICTS+=		ja-mh6-[0-9]*

USE_TOOLS+=		lex

# We choose DOT_LOCKING in our patches because ".lock" files are
# the most common locking mechanism supported by mail software.
# It also works well over NFS.

# Locks supported by `mail.local' are ".lock" and flock(2).

.include "../../mk/bsd.prefs.mk"
# Avoids SEGV in nmh's private version of strcasecmp() under gcc4
.if !empty(PKGSRC_COMPILER:Mgcc*)
CFLAGS+=		-O1
.endif

.include "options.mk"

# Mail Transport Agent - either "smtp" or "sendmail"
NMH_MTA?=		smtp

GNU_CONFIGURE=		yes

GNU_CONFIGURE_LIBDIR=	${PREFIX}/libexec/nmh
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-mts=${NMH_MTA:Q}
CONFIGURE_ARGS+=	--without-readline

DOCDIR=			share/doc/nmh
EGDIR=			${PREFIX}/share/examples/nmh
INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

BUILD_DEFS+=		NMH_MTA NMH_EDITOR NMH_PAGER NMH_HASH_BACKUP

PKG_SYSCONFSUBDIR=	nmh
CONF_FILES=		# empty
.for f in		MailAliases		\
			components		\
			digestcomps		\
			distcomps		\
			forwcomps		\
			mhl.body		\
			mhl.digest		\
			mhl.format		\
			mhl.forward		\
			mhl.headers		\
			mhl.reply		\
			mhn.defaults		\
			mts.conf		\
			rcvdistcomps		\
			rcvdistcomps.outbox	\
			replcomps		\
			replgroupcomps		\
			scan.MMDDYY		\
			scan.YYYYMMDD		\
			scan.default		\
			scan.mailx		\
			scan.nomime		\
			scan.size		\
			scan.time		\
			scan.timely		\
			scan.unseen
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# The configure script checks for arc4random(), but the program uses
# arc4random_buf(); netbsd-5 (and presumably earlier) and some Darwin
# versions has the one but not the other. Just disable it, because all
# it's using the randomness for is message-ids.
.if !empty(MACHINE_PLATFORM:MNetBSD-[1-5].*-*) || \
    !empty(MACHINE_PLATFORM:MDarwin-[1-9].*-*) || \
    !empty(MACHINE_PLATFORM:MDarwin-1[0-2].*-*)
CONFIGURE_ENV+=		ac_cv_func_arc4random=no
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/mhn.defaults.dist \
	    ${DESTDIR}${EGDIR}/mhn.defaults

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../databases/gdbm_compat/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ndbm='gdbm_compat -lgdbm'
CONFIGURE_ARGS+=	--with-ndbmheader=ndbm.h
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
