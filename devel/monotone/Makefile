# $NetBSD: Makefile,v 1.45 2007/10/07 16:31:37 jmmv Exp $
#

DISTNAME=	monotone-0.36
PKGREVISION=	3
CATEGORIES=	devel scm
MASTER_SITES=	http://monotone.ca/downloads/0.36/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://monotone.ca/
COMMENT=	Free distributed version control system

GCC_REQD+=		3.0
GNU_CONFIGURE=		yes
INFO_FILES=		yes
UNLIMIT_RESOURCES+=	datasize
USE_TOOLS+=		gmake makeinfo
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	BOOST_SUFFIX=-mt

PKG_OPTIONS_VAR=	PKG_OPTIONS.monotone
PKG_SUPPORTED_OPTIONS=	inet6

CHECK_INTERPRETER_SKIP+=	share/monotone/contrib/*
CHECK_PORTABILITY_SKIP+=	debian/*

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/monotone
	cd ${WRKSRC} && rm -rf contrib/.deps && \
	    pax -rw -pp -pm contrib \
	    ${DESTDIR}${PREFIX}/share/monotone
	cd ${WRKSRC} && pax -rw -pp -pm figures/*.png \
	    ${DESTDIR}${PREFIX}/share/doc/monotone

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
