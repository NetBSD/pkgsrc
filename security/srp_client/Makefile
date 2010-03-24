# $NetBSD: Makefile,v 1.39 2010/03/24 19:43:28 asau Exp $

DISTNAME=		srp-1.4.4
PKGNAME=		srp-client-1.4.4
PKGREVISION=		2
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.zedz.net/pub/crypto/programs/srp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://srp.stanford.edu/
COMMENT=		Client programs using Secure Remote Password protocol
LICENSE=		srp_client-license

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=		Licensor makes vague patent claims.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

CRYPTO=			yes
GNU_CONFIGURE=		yes

CPPFLAGS+=		-Dunix=1
#CPPFLAGS+=		-Dkrb_get_err_text=k_strerror

CONFIGURE_ARGS+=	--with-srp --with-cast --enable-loginf

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--with-krb4

.include "../../mk/bsd.prefs.mk"

SED_PATTERN=	-e "s,include/kerberos,include/kerberosIV,"
.if ${MACHINE_PLATFORM:MNetBSD-[01].[0-4]*-i386} == ""
SED_PATTERN+=	-e "s,-ldes,-ldes -lroken -lcom_err -lcrypt,"
.else
SED_PATTERN+=	-e "s,-ldes,-ldes -lcom_err,"
.endif

post-patch:
	for FILE in ftp/ftp/Makefile.in ftp/ftpd/Makefile.in		\
		telnet/configure.in telnet/configure;			\
	do								\
		cd ${WRKSRC} &&						\
		${SED}  ${SED_PATTERN} $$FILE > $$FILE.patched &&	\
		${MV} $$FILE.patched $$FILE;				\
	done
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/telnet/telnet/telnet \
	    ${DESTDIR}${PREFIX}/bin/srptelnet
	${INSTALL_DATA} ${WRKSRC}/telnet/telnet/telnet.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/srptelnet.1
	${INSTALL_PROGRAM} ${WRKSRC}/ftp/ftp/ftp ${DESTDIR}${PREFIX}/bin/srpftp
	${INSTALL_DATA} ${WRKSRC}/ftp/ftp/ftp.M ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/srpftp.1

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
