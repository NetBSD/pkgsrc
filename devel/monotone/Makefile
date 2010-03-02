# $NetBSD: Makefile,v 1.61 2010/03/02 20:01:23 jmmv Exp $
#

DISTNAME=	monotone-0.46
CATEGORIES=	devel scm
MASTER_SITES=	http://monotone.ca/downloads/0.46/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://monotone.ca/
COMMENT=	Free distributed version control system

PKG_DESTDIR_SUPPORT=	user-destdir

GCC_REQD+=		3.0
GNU_CONFIGURE=		yes
INFO_FILES=		yes
TEST_TARGET=		check
UNLIMIT_RESOURCES+=	datasize
USE_TOOLS+=		gmake makeinfo pax pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-system-pcre

PKG_OPTIONS_VAR=	PKG_OPTIONS.monotone
PKG_SUPPORTED_OPTIONS=	inet6

CHECK_INTERPRETER_SKIP+=	share/monotone/contrib/*
CHECK_PORTABILITY_SKIP+=	debian/*

REPLACE_SH=			mtnopt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/monotone
	cd ${WRKSRC} && rm -rf contrib/.deps && \
	    pax -rw -pm contrib \
	    ${DESTDIR}${PREFIX}/share/monotone
	cd ${WRKSRC} && pax -rw -pm figures/*.png \
	    ${DESTDIR}${PREFIX}/share/doc/monotone

BUILDLINK_API_DEPENDS.pcre+=	pcre>=7.6

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
