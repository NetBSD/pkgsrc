# $NetBSD: Makefile,v 1.84 2014/09/06 16:07:43 schnoebe Exp $

DISTNAME=		nmh-1.6
CATEGORIES=		mail
MASTER_SITES=		http://savannah.nongnu.org/download/nmh/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/nmh/
COMMENT=		Cleaned up MH mailer suite
LICENSE=		modified-bsd

MAKE_JOBS_SAFE=		no

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

post-install:
	${INSTALL_DATA} ${FILESDIR}/mhn.defaults.dist \
	    ${DESTDIR}${EGDIR}/mhn.defaults

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../databases/gdbm_compat/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ndbm='gdbm_compat -lgdbm'
CONFIGURE_ARGS+=	--with-ndbmheader=ndbm.h
.endif

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
