# $NetBSD: Makefile,v 1.4 2012/06/16 22:55:25 pettai Exp $
#

DISTNAME=	zkt-1.1.0
CATEGORIES=	security
MASTER_SITES=	http://www.hznet.de/dns/zkt/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.hznet.de/dns/zkt/
COMMENT=	DNSSEC Zone Key Tool
LICENSE=	original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-configpath=${PKG_SYSCONFDIR}/zkt
#CONFIGURE_ARGS+=	--enable-configpath=/var/chroot/named/etc

INSTALLATION_DIRS=	sbin share/doc/zkt ${PKGMANDIR}/man8 etc/zkt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-conf \
		${DESTDIR}${PREFIX}/sbin/zkt-conf
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-keyman \
		${DESTDIR}${PREFIX}/sbin/zkt-keyman
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-ls \
		${DESTDIR}${PREFIX}/sbin/zkt-ls
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-signer \
		${DESTDIR}${PREFIX}/sbin/zkt-signer
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-soaserial \
		${DESTDIR}${PREFIX}/sbin/zkt-soaserial
	${INSTALL_MAN} ${WRKSRC}/man/zkt-conf.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/zkt-conf.8
	${INSTALL_MAN} ${WRKSRC}/man/zkt-ls.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/zkt-ls.8
	${INSTALL_MAN} ${WRKSRC}/man/zkt-keyman.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/zkt-keyman.8
	${INSTALL_MAN} ${WRKSRC}/man/zkt-signer.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/zkt-signer.8
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/zkt/README
	${INSTALL_DATA} ${WRKSRC}/README.logging \
		${DESTDIR}${PREFIX}/share/doc/zkt/README.logging

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
