# $NetBSD: Makefile,v 1.56 2002/12/07 02:39:04 schmonz Exp $
#

DISTNAME=	racoon-20021120a
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.kame.net/
COMMENT=	KAME racoon IKE daemon

CRYPTO=		yes

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
PKG_FAIL_REASON+= "${PKGNAME} requires ipsec-ready ${OPSYS}"
.endif

BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=	yes

CONFLICTS+=	racoon-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/racoon

PKG_SYSCONFSUBDIR?=	racoon

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-debug
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}
.if defined(PKGREVISION)
CONFIGURE_ARGS+=--with-pkgversion=netbsd-pkgsrc-20021120anb${PKGREVISION}
.else
CONFIGURE_ARGS+=--with-pkgversion=netbsd-pkgsrc-20021120a
.endif

pre-configure:
	(cd ${WRKSRC}/../libipsec; ${MAKE})

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/racoon
	for i in FAQ README.certificate README.gssapi; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$i ${PREFIX}/share/doc/racoon; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/racoon
	${INSTALL_DATA} ${WRKSRC}/samples/racoon.conf.sample \
		${PREFIX}/share/examples/racoon

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
