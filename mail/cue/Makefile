# $NetBSD: Makefile,v 1.56 2008/05/02 03:55:38 obache Exp $

DISTNAME=	cue-snap-20080211
PKGNAME=	${DISTNAME:S/snap-//}
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	mh-e like mail user agent

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGSRC_COMPILER} == "ido"
CPPFLAGS+=	-DNO_ATTRIBUTE
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.cue
PKG_SUPPORTED_OPTIONS=	canna idea inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6) && (${OPSYS} != "SunOS")
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.  include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canna=${BUILDLINK_PREFIX.canna}
.else
CONFIGURE_ARGS+=	--without-canna
.endif

.if !empty(PKG_OPTIONS:Midea)
CONFIGURE_ARGS+=	--enable-idea
.endif

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

INSTALLATION_DIRS=	bin

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cue ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/cue
	${INSTALL_DATA} ${WRKSRC}/sample.cuerc \
		${DESTDIR}${PREFIX}/share/examples/cue
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cue
	${INSTALL_DATA} ${WRKSRC}/cue.hlp ${DESTDIR}${PREFIX}/share/doc/cue

.include "../../mk/bsd.pkg.mk"
