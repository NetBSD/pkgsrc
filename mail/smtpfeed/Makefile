# $NetBSD: Makefile,v 1.25 2005/12/05 20:50:35 rillig Exp $

DISTNAME=	smtpfeed-1.18
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/smtpfeed/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/ \
		ftp://ftp.sendmail.org/ucb/src/sendmail/ \
		http://freefall.freebsd.org/~itojun/distfiles/

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.kyoto.wide.ad.jp/mta/sendmail.html#smtpfeed
COMMENT=	SMTP Fast Exploding External Deliverer for Sendmail

# sendmail 8.x with WIDE patch works better with it, than stock 8.x.
# require sendmail from pkgsrc.
#DEPENDS+=	sendmail>=8.9.3:../../mail/sendmail

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX:Q}/libexec
# use bind8?
#CONFIGURE_ARGS+=	--with-bind8

DOCS=	COPYRIGHT FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
	ML-ADMIN ML-ADMIN.j OPTIONS OPTIONS.j README README.j \
	RELEASE.NOTE SIGNAL SIGNAL.j TODO
DOCDIR=	${PREFIX}/share/doc/smtpfeed

BUILD_DEFS+=    USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=--enable-ipv6
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/smtpfeed.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${DOCDIR}
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCDIR}; \
	done

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
