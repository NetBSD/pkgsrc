# $NetBSD: Makefile,v 1.1.1.1 1999/06/18 19:18:17 jlam Exp $
#

DISTNAME=		srp-1.4.4
PKGNAME=		srp-client-1.4.4
CATEGORIES=		security net
MASTER_SITES=		ftp://paris.arcot.com/pub/srp/ \
			ftp://srp.stanford.edu/pub/srp/ \
			ftp://labrea.stanford.edu/pub/srp/ \
			http://www.nit.gwu.edu/srp/ \
			ftp://ftp.kfki.hu/pub/packages/security/srp/ \
			ftp://ftp.bandit.co.jp/pub/srp/ \
			ftp://ftp.win.or.jp/pub/network/security/srp/ \
			ftp://ftp.replay.com/pub/crypto/crypto/APPS/srp/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://srp.stanford.edu/srp/

DEPENDS+=		gmp-2.0.2:../../devel/gmp

RESTRICTED=             "Crypto; export-controlled"
MIRROR_DISTFILE=        no

GNU_CONFIGURE=		yes

CPPFLAGS+=		-Dunix=1
CPPFLAGS+=		-I${LOCALBASE}/include	# gmp.h
LDFLAGS+=		-L${LOCALBASE}/lib	# libgmp.a

CONFIGURE_ARGS+=	--with-srp --with-cast --enable-loginf
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--with-krb4
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/telnet/telnet/telnet \
		${PREFIX}/bin/srptelnet
	$(INSTALL_DATA) ${WRKSRC}/telnet/telnet/telnet.1 \
		${PREFIX}/man/man1/srptelnet.1
	${INSTALL_PROGRAM} ${WRKSRC}/ftp/ftp/ftp ${PREFIX}/bin/srpftp
	${INSTALL_DATA} ${WRKSRC}/ftp/ftp/ftp.M ${PREFIX}/man/man1/srpftp.1

.include "../../mk/bsd.pkg.mk"
