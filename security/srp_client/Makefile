# $NetBSD: Makefile,v 1.18 2001/11/29 19:46:13 jlam Exp $

DISTNAME=		srp-1.4.4
PKGNAME=		srp-client-1.4.4
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.win.or.jp/pub/network/security/srp/

MAINTAINER=		jlam@netbsd.org
#HOMEPAGE=		http://srp.stanford.edu/srp/
COMMENT=		client programs using Secure Remote Password protocol

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
DEPENDS+=		gmp>=2.0.2:../../devel/gmp

LICENSE=		srp_client-license

CRYPTO=			yes
GNU_CONFIGURE=		yes

CPPFLAGS+=		-Dunix=1
#CPPFLAGS+=		-Dkrb_get_err_text=k_strerror
CPPFLAGS+=		-I${LOCALBASE}/include	# gmp.h
LDFLAGS+=		-L${LOCALBASE}/lib	# libgmp.a

CONFIGURE_ARGS+=	--with-srp --with-cast --enable-loginf

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--with-krb4

.include "../../mk/bsd.prefs.mk"

SED_PATTERN=	-e "s,include/kerberos,include/kerberosIV,"
.if ${MACHINE_PLATFORM:MNetBSD-[01].[0-4]*-i386} == ""
SED_PATTERN+=	-e "s,-ldes,-ldes -lroken -lcom_err,"
.else
SED_PATTERN+=	-e "s,-ldes,-ldes -lcom_err,"
.endif

post-patch:
	for FILE in ftp/ftp/Makefile.in ftp/ftpd/Makefile.in		\
		telnet/configure telnet/configure.in;			\
	do								\
		cd ${WRKSRC} &&						\
		${SED}  ${SED_PATTERN} $$FILE > $$FILE.patched &&	\
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
