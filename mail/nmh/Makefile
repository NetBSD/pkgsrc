# $NetBSD: Makefile,v 1.55 2005/01/16 19:19:46 jmmv Exp $
# FreeBSD Id: Makefile,v 1.2 1997/08/04 06:51:28 markm Exp
#

DISTNAME=		nmh-1.0.4
PKGREVISION=		6
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mhost.com/pub/nmh/ \
			ftp://ftp.gw.com/pub/unix/mail/mh/nmh/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.nongnu.org/nmh/
COMMENT=		Cleaned up MH mailer suite

CONFLICTS=		ja-mh-[0-9]*
CONFLICTS+=		ja-mh6-[0-9]*

# We choose DOT_LOCKING in our patches because ".lock" files are
# the most common locking mechanism supported by mail software.
# It also works well over NFS.

# Locks supported by `mail.local' are ".lock" and flock(2).

.include "../../mk/bsd.prefs.mk"

# Mail Transport Agent - either "smtp" or "sendmail"
NMH_MTA?=		smtp

GNU_CONFIGURE=		# defined
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec/nmh
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-nmh-pop
CONFIGURE_ARGS+=	--with-mts=${NMH_MTA}

.ifdef NMH_EDITOR
CONFIGURE_ARGS+=	--with-editor=${NMH_EDITOR}
.endif

.ifdef NMH_PAGER
CONFIGURE_ARGS+=	--with-pager=${NMH_PAGER}
.endif

.if defined(KERBEROS)
PKG_USE_KERBEROS=	# defined
.if ${OPSYS} == "NetBSD"
LIBS=			-lroken -lcrypt -lcom_err
.endif
CONFIGURE_ARGS+=	--with-krb4
.else
CONFIGURE_ARGS+=	--without-krb4
.endif

DOCDIR=			share/doc/nmh
EGDIR=	 		${PREFIX}/share/examples/nmh

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
			scan.unseen		\
			tmac.h
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.undef f

.if defined(NMH_HASH_BACKUP) && (${NMH_HASH_BACKUP} == yes)
post-configure:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak
	${SED} -e 's/^\(#define  *BACKUP_PREFIX\)  *.*/\1 "#"/' \
	    < ${WRKSRC}/config.h.bak > ${WRKSRC}/config.h
.endif

# This hopefully makes sure the permissions and ownership are right.
pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	for f in `${GREP} '^${DOCDIR}/' ${PKGDIR}/PLIST`; do \
	    ${INSTALL_DATA} ${WRKSRC}/`${BASENAME} $$f` ${PREFIX}/${DOCDIR}; \
	done
	${INSTALL_DATA} ${FILESDIR}/mhn.defaults.dist ${EGDIR}/mhn.defaults

.include "../../mk/bsd.pkg.mk"
