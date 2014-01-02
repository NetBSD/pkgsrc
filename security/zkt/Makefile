# $NetBSD: Makefile,v 1.9 2014/01/02 00:50:07 dholland Exp $
#

DISTNAME=	zkt-1.1.2
CATEGORIES=	security
MASTER_SITES=	http://www.hznet.de/dns/zkt/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.hznet.de/dns/zkt/
COMMENT=	DNSSEC Zone Key Tool
LICENSE=	original-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-configpath=${PKG_SYSCONFDIR}/zkt
#CONFIGURE_ARGS+=	--enable-configpath=/var/chroot/named/etc

INSTALLATION_DIRS=	sbin share/doc/zkt ${PKGMANDIR}/man8 etc/zkt

.include "../../mk/bsd.prefs.mk"

# NetBSD has bind in base, util path=/usr/sbin
.if ${OPSYS} == "NetBSD" && exists(/usr/sbin/dnssec-keygen)
CONFIGURE_ARGS+=	--enable-bind_util_path=/usr/sbin
.endif

# DragonFly uses pkgsrc bind, so the util path must be explicitly defined
# Without any global bind package to point to, pick the latest one and
# hope one of the other 3 bind packages isn't already installed because
# this one will fail to build due to conflict in that case.

.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--enable-bind_util_path=${BUILDLINK_PREFIX.bind}/sbin
.include "../../net/bind99/buildlink3.mk"
.endif

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
