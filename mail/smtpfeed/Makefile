# $NetBSD: Makefile,v 1.2 1999/11/29 08:33:30 itojun Exp $
# KAME $Id: Makefile,v 1.2 1999/11/29 08:33:30 itojun Exp $
# Based on FreeBSD Id: Makefile,v 1.27 1999/04/03 08:25:18 itojun Exp
#

DISTNAME=	smtpfeed-1.02
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/smtpfeed/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/ \
		ftp://ftp.sendmail.org/ucb/src/sendmail/ \
		http://freefall.freebsd.org/~itojun/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SENDMAIL}${EXTRACT_SUFX} \
		${SENDMAILPATCH}.patch.gz

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.kyoto.wide.ad.jp/mta/sendmail.html#smtpfeed

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${SENDMAIL}${EXTRACT_SUFX}
PATCH_SENDMAIL_ARGS=	-d ${WRKSRC_SENDMAIL} -E ${PATCH_DIST_STRIP}
NO_PACKAGE=	"complex configuration for sendmail.cf needed"

SENDMAILVER=	8.9.3
SENDMAIL=	sendmail.${SENDMAILVER}
SENDMAILDIR=	sendmail-${SENDMAILVER}
SENDMAILPATCH=	sendmail893+3.2W
WRKSRC_SMTPFEED=	${WRKSRC}
WRKSRC_SENDMAIL=	${WRKDIR}/${SENDMAILDIR}/src

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec
# use bind8?
#CONFIGURE_ARGS+=	--with-bind8

DOCS=	COPYRIGHT FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
	OPTIONS OPTIONS.j README README.j RELEASE.NOTE SIGNAL SIGNAL.j TODO
DOCDIR=	${PREFIX}/share/doc/smtpfeed

BUILD_DEFS+=    USE_INET6

.include "../../mk/bsd.prefs.mk"

post-patch:
	@${ECHO_MSG} "===>  Applying smtpfeed patch ${SENDMAILPATCH} to ${SENDMAIL}"
	@(cd ${_DISTDIR}; for i in ${SENDMAILPATCH}.patch.gz; do \
		${GZCAT} $$i | ${PATCH} ${PATCH_SENDMAIL_ARGS}; \
	done)
	${CP} -f ${FILESDIR}/site.config-v6.kame ${WRKSRC_SENDMAIL}

post-build:
	@${ECHO_MSG} "===>  Building patched ${SENDMAIL}"
.if defined(USE_INET6) && ${USE_INET6} == YES
	@(cd ${WRKSRC_SENDMAIL}; sh makesendmail -f site.config-v6.kame)
.else
	@(cd ${WRKSRC_SENDMAIL}; sh makesendmail )
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCDIR}; \
	done
.endif
	@${SED} -e 's#/usr/local#${PREFIX}#' ${PKGDIR}/MESSAGE

install-sendmail:
	(cd ${WRKSRC_SENDMAIL}; sh makesendmail install)

.include "../../mk/bsd.pkg.mk"
