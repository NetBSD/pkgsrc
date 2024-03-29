# $NetBSD: Makefile,v 1.39 2022/12/15 11:30:01 jperkin Exp $

DISTNAME=	smtpfeed-1.23
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/smtpfeed/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://member.wide.ad.jp/wg/smtp/smtpfeed.html
COMMENT=	SMTP Fast Exploding External Deliverer for Sendmail
LICENSE=	original-bsd

# sendmail 8.x with WIDE patch works better with it, than stock 8.x.
# require sendmail from pkgsrc.
#DEPENDS+=	sendmail>=8.9.3:../../mail/sendmail

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX:Q}/libexec
# configure tries to be clever, so force our setting
CONFIGURE_ENV+=		my_cv_path_lib_exec=${PREFIX:Q}/libexec
# use bind8?
#CONFIGURE_ARGS+=	--with-bind8

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil
LDFLAGS.SunOS+=			-lsocket -lnsl -lresolv

DOCS=	COPYRIGHT FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
	ML-ADMIN ML-ADMIN.j OPTIONS OPTIONS.j README README.j \
	RELEASE.NOTE SIGNAL SIGNAL.j TODO

PKG_OPTIONS_VAR=	PKG_OPTIONS.smtpfeed
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man8 share/doc/smtpfeed
INSTALL_MAKE_FLAGS+=	libexecdir=${DESTDIR}${PREFIX}/libexec

post-install:
	${INSTALL_MAN} ${WRKSRC}/smtpfeed.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/share/doc/smtpfeed; \
	done

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
