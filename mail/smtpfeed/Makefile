# $NetBSD: Makefile,v 1.28 2007/01/07 09:13:59 rillig Exp $

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
# configure tries to be clever, so force our setting
CONFIGURE_ENV+=	my_cv_path_lib_exec=${PREFIX:Q}/libexec
# use bind8?
#CONFIGURE_ARGS+=	--with-bind8

DOCS=	COPYRIGHT FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
	ML-ADMIN ML-ADMIN.j OPTIONS OPTIONS.j README README.j \
	RELEASE.NOTE SIGNAL SIGNAL.j TODO

BUILD_DEFS+=    USE_INET6

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man8 share/doc/smtpfeed

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=--enable-ipv6
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/smtpfeed.8 ${PREFIX}/${PKGMANDIR}/man8
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/smtpfeed; \
	done

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
