# $NetBSD: Makefile,v 1.11 2001/02/17 17:50:08 wiz Exp $
#

DISTNAME=		srp-1.4.4
PKGNAME=		srp-client-1.4.4
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.win.or.jp/pub/network/security/srp/

MAINTAINER=		jlam@netbsd.org
#HOMEPAGE=		http://srp.stanford.edu/srp/
COMMENT=		client programs using Secure Remote Password protocol

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=		${LOCALBASE}/bin/automake:../../devel/automake
DEPENDS+=		gmp>=2.0.2:../../devel/gmp

CRYPTO=			yes
GNU_CONFIGURE=		yes

CPPFLAGS+=		-Dunix=1
CPPFLAGS+=		-I${LOCALBASE}/include	# gmp.h
LDFLAGS+=		-L${LOCALBASE}/lib	# libgmp.a

CONFIGURE_ARGS+=	--with-srp --with-cast --enable-loginf
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--with-krb4

post-patch:
	for FILE in ftp/ftp/Makefile.in ftp/ftpd/Makefile.in		\
		telnet/configure telnet/configure.in;			\
	do								\
		cd ${WRKSRC} &&						\
		${SED}  -e "s,include/kerberos,include/kerberosIV,"	\
			-e "s,-ldes,-ldes -lroken -lcom_err,"		\
			$$FILE > $$FILE.patched &&			\
		${MV} $$FILE.patched $$FILE;				\
	done
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/telnet/telnet/telnet \
		${PREFIX}/bin/srptelnet
	${INSTALL_DATA} ${WRKSRC}/telnet/telnet/telnet.1 \
		${PREFIX}/man/man1/srptelnet.1
	${INSTALL_PROGRAM} ${WRKSRC}/ftp/ftp/ftp ${PREFIX}/bin/srpftp
	${INSTALL_DATA} ${WRKSRC}/ftp/ftp/ftp.M ${PREFIX}/man/man1/srpftp.1

.include "../../mk/bsd.pkg.mk"
