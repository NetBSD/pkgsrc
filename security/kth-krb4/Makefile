# $NetBSD: Makefile,v 1.8 2001/02/17 17:49:47 wiz Exp $
#

DISTNAME=		krb4-1.0.1
PKGNAME=		kth-krb4-1.0.1
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@netbsd.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/
COMMENT=		Kerberos IV distribution from KTH

CRYPTO=			yes
GNU_CONFIGURE=		yes
#USE_GTEXINFO=		yes #not currently needed

post-patch:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${WRKSRC}/lib/kafs/kafs.h                                    \
		>${WRKSRC}/lib/kafs/kafs.h.sed
	@${MV} ${WRKSRC}/lib/kafs/kafs.h.sed ${WRKSRC}/lib/kafs/kafs.h

post-install:
	@${MKDIR} ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.conf ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.realms ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/inetd.conf.changes ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${FILESDIR}/services.diff ${PREFIX}/share/examples/kth-krb4

.include "../../mk/bsd.pkg.mk"
