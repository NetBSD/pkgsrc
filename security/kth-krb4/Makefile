# $NetBSD: Makefile,v 1.1.1.1 2000/05/25 17:57:27 wennmach Exp $
#

DISTNAME=		krb4-1.0.1
PKGNAME=		kth-krb4-1.0.1
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@netbsd.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no

GNU_CONFIGURE=		yes

post-install:
	@${MKDIR} ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.conf ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.realms ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/inetd.conf.changes ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${PKGDIR}/services.diff ${PREFIX}/share/examples/kth-krb4

.include "../../mk/bsd.pkg.mk"
