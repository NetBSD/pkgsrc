# $NetBSD: Makefile,v 1.13 2001/08/02 12:46:48 wennmach Exp $
#

DISTNAME=		krb4-1.0.9
PKGNAME=		kth-krb4-1.0.9
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@netbsd.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/
COMMENT=		Kerberos IV distribution from KTH

CONFLICTS+=		wu-ftpd-*
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
	${INSTALL_DATA} ${FILESDIR}/services-1.4.2.diff ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${FILESDIR}/services-1.5.diff ${PREFIX}/share/examples/kth-krb4

.include "../../mk/bsd.pkg.mk"
