# $NetBSD: Makefile,v 1.3 2011/12/17 23:43:43 sbd Exp $
#

DISTNAME=	zkt-1.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zkt/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://zkt.sourceforge.net/
COMMENT=	DNSSEC Zone Key Tool
LICENSE=	original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-configpath=${PKG_SYSCONFDIR}/zkt
#CONFIGURE_ARGS+=	--enable-configpath=/var/chroot/named/etc

INSTALLATION_DIRS=	sbin share/doc/zkt ${PKGMANDIR}/man8 etc/zkt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnssec-zkt \
		${DESTDIR}${PREFIX}/sbin/dnssec-zkt
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-conf \
		${DESTDIR}${PREFIX}/sbin/zkt-conf
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-keyman \
		${DESTDIR}${PREFIX}/sbin/zkt-keyman
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-ls \
		${DESTDIR}${PREFIX}/sbin/zkt-ls
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-signer \
		${DESTDIR}${PREFIX}/sbin/zkt-signer
	${LN} -f ${DESTDIR}${PREFIX}/sbin/zkt-signer \
		${DESTDIR}${PREFIX}/sbin/dnssec-signer
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-soaserial \
		${DESTDIR}${PREFIX}/sbin/zkt-soaserial
	${INSTALL_MAN} ${WRKSRC}/man/dnssec-zkt.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/dnssec-zkt.8
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

#.include "../../net/bind96/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
