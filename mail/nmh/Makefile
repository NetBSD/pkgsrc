# $NetBSD: Makefile,v 1.101 2019/07/01 04:08:30 ryoon Exp $

DISTNAME=		nmh-1.7.1
PKGREVISION=		5
CATEGORIES=		mail
MASTER_SITES=		https://download.savannah.nongnu.org/releases/nmh/

MAINTAINER=		leot@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/nmh/
COMMENT=		Cleaned up MH mailer suite
LICENSE=		modified-bsd

CONFLICTS=		ja-mh-[0-9]*
CONFLICTS+=		ja-mh6-[0-9]*

USE_TOOLS+=		lex

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

# Mail Transport Agent - either "smtp" or "sendmail"
NMH_MTA?=		smtp

GNU_CONFIGURE=		yes

GNU_CONFIGURE_LIBDIR=	${PREFIX}/libexec/nmh
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--with-mts=${NMH_MTA:Q}
CONFIGURE_ARGS+=	--without-readline

DOCDIR=			share/doc/nmh
EGDIR=			${PREFIX}/share/examples/nmh
INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

BUILD_DEFS+=		NMH_MTA NMH_EDITOR NMH_PAGER NMH_HASH_BACKUP PKG_SYSCONFBASE

PKG_SYSCONFSUBDIR=	nmh
CONF_FILES=		# empty
.for f in		MailAliases		\
			components		\
			digestcomps		\
			distcomps		\
			forwcomps		\
			mhical.12hour		\
			mhical.24hour		\
			mhl.body		\
			mhl.digest		\
			mhl.format		\
			mhl.forward		\
			mhl.headers		\
			mhl.reply		\
			mhl.replywithoutbody	\
			mhn.defaults		\
			mhshow.marker		\
			mts.conf		\
			rcvdistcomps		\
			rcvdistcomps.outbox	\
			replcomps		\
			replgroupcomps		\
			rmmproc.messageid	\
			scan.MMDDYY		\
			scan.YYYYMMDD		\
			scan.curses		\
			scan.default		\
			scan.highlighted	\
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

TEST_TARGET=		check

post-install:
	${INSTALL_DATA} ${FILESDIR}/mhn.defaults.dist \
	    ${DESTDIR}${EGDIR}/mhn.defaults

.if ${OPSYS} == "Linux"
.include "../../databases/gdbm_compat/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ndbm='gdbm_compat -lgdbm'
CONFIGURE_ARGS+=	--with-ndbmheader=ndbm.h
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
