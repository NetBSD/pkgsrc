# $NetBSD: Makefile,v 1.11 2001/03/29 21:17:40 wennmach Exp $
#

DISTNAME=		krb4-1.0.1
PKGNAME=		kth-krb4-1.0.1
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@netbsd.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/
COMMENT=		Kerberos IV distribution from KTH

CONFLICTS+=		wu-ftpd-*
CONFLICTS+=		cyrus-imapd-*
CONFLICTS+=		lukemftp-*
CONFLICTS+=		zephyr-*
CONFLICTS+=		libdes-*

CRYPTO=			yes
GNU_CONFIGURE=		yes

post-patch:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${WRKSRC}/lib/kafs/kafs.h                                    \
		>${WRKSRC}/lib/kafs/kafs.h.sed
	@${MV} ${WRKSRC}/lib/kafs/kafs.h.sed ${WRKSRC}/lib/kafs/kafs.h

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.conf ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.realms ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/inetd.conf.changes ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${FILESDIR}/services.diff ${PREFIX}/share/examples/kth-krb4

.include "../../mk/bsd.pkg.mk"
