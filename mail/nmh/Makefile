# $NetBSD: Makefile,v 1.72 2011/12/03 09:25:45 sbd Exp $

DISTNAME=		nmh-1.3
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://savannah.nongnu.org/download/nmh/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/nmh/
COMMENT=		Cleaned up MH mailer suite

PKG_DESTDIR_SUPPORT=	user-destdir

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

CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec/nmh
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-nmh-pop
CONFIGURE_ARGS+=	--with-mts=${NMH_MTA:Q}

.if defined(NMH_EDITOR)
CONFIGURE_ARGS+=	--with-editor=${NMH_EDITOR:Q}
.endif

.if defined(NMH_PAGER)
CONFIGURE_ARGS+=	--with-pager=${NMH_PAGER:Q}
.endif

.if defined(KERBEROS)
PKG_USE_KERBEROS=	yes
.if ${OPSYS} == "NetBSD"
LIBS+=			-lroken -lcrypt -lcom_err
.endif
CONFIGURE_ARGS+=	--with-krb4
.else
CONFIGURE_ARGS+=	--without-krb4
.endif

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
	for f in `${GREP} '^${DOCDIR}/' ${PKGDIR}/PLIST`; do \
	    ${INSTALL_DATA} ${WRKSRC}/docs/`${BASENAME} $$f` \
		${DESTDIR}${PREFIX}/${DOCDIR}; \
	done
	${INSTALL_DATA} ${FILESDIR}/mhn.defaults.dist \
	    ${DESTDIR}${EGDIR}/mhn.defaults

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../databases/gdbm_compat/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ndbm='gdbm_compat -lgdbm'
CONFIGURE_ARGS+=	--with-ndbmheader=ndbm.h
.endif

.include "../../mk/bsd.pkg.mk"
