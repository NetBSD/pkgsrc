# $NetBSD: Makefile,v 1.70 2004/10/03 00:18:12 tv Exp $
#

DISTNAME=	racoon-20040617a
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.kame.net/
COMMENT=	KAME racoon IKE daemon

CONFLICTS+=	racoon-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/racoon
USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes

CRYPTO=		yes

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
PKG_FAIL_REASON+= "${PKGNAME} requires ipsec-ready ${OPSYS}"
.endif

BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	racoon
RCD_SCRIPTS=	racoon
CONF_FILES=	${PREFIX}/share/examples/racoon/racoon.conf.sample \
		${PKG_SYSCONFDIR}/racoon.conf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-debug
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}
.if defined(PKGREVISION)
CONFIGURE_ARGS+=--with-pkgversion=netbsd-pkgsrc-20040617anb${PKGREVISION}
.else
CONFIGURE_ARGS+=--with-pkgversion=netbsd-pkgsrc-20040617a
.endif

pre-configure:
	(cd ${WRKSRC}/../libipsec; ${MAKE} ${MAKE_ENV})

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/racoon
	for i in FAQ README.certificate README.gssapi; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$i ${PREFIX}/share/doc/racoon; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/racoon
	${INSTALL_DATA} ${WRKSRC}/samples/racoon.conf.sample \
		${PREFIX}/share/examples/racoon

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
