# $NetBSD: Makefile,v 1.1.1.1 2010/03/13 19:19:51 pettai Exp $
#

DISTNAME=	zkt-0.99c
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
	${INSTALL_PROGRAM} ${WRKSRC}/dnssec-signer \
		${DESTDIR}${PREFIX}/sbin/dnssec-signer
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-soaserial \
		${DESTDIR}${PREFIX}/sbin/zkt-soaserial
	${INSTALL_MAN} ${WRKSRC}/man/dnssec-zkt.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/dnssec-zkt.8
	${INSTALL_MAN} ${WRKSRC}/man/dnssec-signer.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/dnssec-signer.8
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/zkt/README
	${INSTALL_DATA} ${WRKSRC}/README.logging \
		${DESTDIR}${PREFIX}/share/doc/zkt/README.logging

#.include "../../net/bind96/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
