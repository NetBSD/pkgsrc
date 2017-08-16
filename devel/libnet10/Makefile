# $NetBSD: Makefile,v 1.8 2017/08/16 20:45:35 wiz Exp $
#

DISTNAME=	libnet-1.0.2a
PKGNAME=	${DISTNAME:S/libnet/libnet10/}
PKGREVISION=	3
CATEGORIES=	devel net
#MASTER_SITES=	http://www.packetfactory.net/libnet/dist/deprecated/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.packetfactory.net/libnet/
COMMENT=	C library for portable packet creation and injection
LICENSE=	2-clause-bsd

CONFLICTS=	libnet-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:C/l/L/}

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBNET_CONFIG_CFLAGS="-I${PREFIX}/include/libnet10" \
		LIBNET_CONFIG_LIBS=${LDFLAGS:M*:Q}

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	Makefile.in libnet-config.in
SUBST_SED.vars=		-e 's,@MAN_PREFIX@,${PREFIX}/${PKGMANDIR}/man3,g'
SUBST_SED.vars+=	-e 's!@COMPILER_RPATH_FLAG@!${COMPILER_RPATH_FLAG}!g'

INSTALLATION_DIRS=	bin lib share/examples ${PKGMANDIR}/man3

post-extract:
	${CHMOD} -R a+r ${WRKSRC}/doc

post-install:
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/include/libnet10/libnet.h
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/include/libnet10/libnet/*.h
	${CHMOD} ${MANMODE} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/libnet10.3

.include "../../mk/bsd.pkg.mk"
