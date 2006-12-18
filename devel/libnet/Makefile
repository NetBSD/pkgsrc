# $NetBSD: Makefile,v 1.30 2006/12/18 02:22:40 joerg Exp $
#

DISTNAME=	libnet-1.0.2a
CATEGORIES=	devel net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/deprecated/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/libnet/
COMMENT=	C library for portable packet creation and injection

PKG_INSTALLATION_TYPES=	overwrite pkgviews
CONFLICTS=	libnet-1.1.[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:C/l/L/}

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBNET_CONFIG_CFLAGS="-I${PREFIX}/include" \
		LIBNET_CONFIG_LIBS=${LDFLAGS:M*:Q}

INSTALLATION_DIRS=	bin lib share/examples ${PKGMANDIR}/man3

post-extract:
	${CHMOD} -R a+r ${WRKSRC}/doc

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	Makefile.in
SUBST_SED.man=		-e 's,@MAN_PREFIX@,${PREFIX}/${PKGMANDIR}/man3,g'

.include "../../mk/bsd.pkg.mk"
