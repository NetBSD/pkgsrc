# $NetBSD: Makefile,v 1.6 2000/10/11 16:28:53 wennmach Exp $
#

DISTNAME=		krb4-1.0.1
PKGNAME=		kth-krb4-1.0.1
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@netbsd.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/

CRYPTO=			yes
GNU_CONFIGURE=		yes
#USE_GTEXINFO=		yes #not currently needed

MESSAGE_FILE=		${WRKDIR}/MESSAGE

post-patch:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${WRKSRC}/lib/kafs/kafs.h                                    \
		>${WRKSRC}/lib/kafs/kafs.h.sed
	@${MV} ${WRKSRC}/lib/kafs/kafs.h.sed ${WRKSRC}/lib/kafs/kafs.h

pre-install:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${PKGDIR}/MESSAGE                                            \
		>${MESSAGE_FILE}

post-install:
	@${MKDIR} ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.conf ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.realms ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/inetd.conf.changes ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${FILESDIR}/services.diff ${PREFIX}/share/examples/kth-krb4

.include "../../mk/bsd.pkg.mk"
