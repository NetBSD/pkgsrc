# $NetBSD: Makefile,v 1.6 2000/04/15 13:58:26 itojun Exp $
# KAME $Id: Makefile,v 1.6 2000/04/15 13:58:26 itojun Exp $
# Based on FreeBSD Id: Makefile,v 1.27 1999/04/03 08:25:18 itojun Exp
#

DISTNAME=	smtpfeed-1.05
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/smtpfeed/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/ \
		ftp://ftp.sendmail.org/ucb/src/sendmail/ \
		http://freefall.freebsd.org/~itojun/distfiles/

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.kyoto.wide.ad.jp/mta/sendmail.html#smtpfeed

# WIDE sendmail 8.9.x works better with it, than stock 8.10.x
DEPENDS+=	sendmail-*:../../mail/sendmail

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec
# use bind8?
#CONFIGURE_ARGS+=	--with-bind8

MESSAGE_FILE=	${WRKDIR}/MESSAGE

DOCS=	COPYRIGHT FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
	OPTIONS OPTIONS.j README README.j RELEASE.NOTE SIGNAL SIGNAL.j TODO
DOCDIR=	${PREFIX}/share/doc/smtpfeed

BUILD_DEFS+=    USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=--enable-ipv6
.endif

post-build:
	${SED} -e 's#@@PKGNAME@@#${PKGNAME}#g' \
		-e 's#@@PREFIX@@#${PREFIX}#g' \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCDIR}; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
