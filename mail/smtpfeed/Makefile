# $NetBSD: Makefile,v 1.31 2007/11/17 13:40:16 wiz Exp $

DISTNAME=	smtpfeed-1.18
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/smtpfeed/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/ \
		ftp://ftp.sendmail.org/ucb/src/sendmail/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kyoto.wide.ad.jp/mta/sendmail.html#smtpfeed
COMMENT=	SMTP Fast Exploding External Deliverer for Sendmail

# sendmail 8.x with WIDE patch works better with it, than stock 8.x.
# require sendmail from pkgsrc.
#DEPENDS+=	sendmail>=8.9.3:../../mail/sendmail

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX:Q}/libexec
# configure tries to be clever, so force our setting
CONFIGURE_ENV+=		my_cv_path_lib_exec=${PREFIX:Q}/libexec
# use bind8?
#CONFIGURE_ARGS+=	--with-bind8

DOCS=	COPYRIGHT FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
	ML-ADMIN ML-ADMIN.j OPTIONS OPTIONS.j README README.j \
	RELEASE.NOTE SIGNAL SIGNAL.j TODO

PKG_OPTIONS_VAR=	PKG_OPTIONS.smtpfeed
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man8 share/doc/smtpfeed

post-install:
	${INSTALL_MAN} ${WRKSRC}/smtpfeed.8 ${PREFIX}/${PKGMANDIR}/man8
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/smtpfeed; \
	done

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
