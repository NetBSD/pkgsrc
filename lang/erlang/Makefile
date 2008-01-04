# $NetBSD: Makefile,v 1.34 2008/01/04 14:05:05 ghen Exp $

DISTNAME=		otp_src_${DIST_VERSION_MAJOR}-${DIST_VERSION_MINOR}
PKGNAME=		erlang-${ERLANG_VERSION}
CATEGORIES=		lang
MASTER_SITES=		http://www.erlang.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.erlang.org/
COMMENT=		Concurrent functional programming language

DIST_SUBDIR=		erlang

GNU_CONFIGURE=		yes
OVERRIDE_DIRDEPTH=	4
USE_TOOLS+=		gmake perl:run

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl:Q}

SUBST_CLASSES+=		target
SUBST_STAGE.target=	post-patch
SUBST_FILES.target=	make/target.mk
SUBST_SED.target=	-e "s|=.*config.guess)|= ${MACHINE_GNU_PLATFORM}|"
SUBST_MESSAGE.target=	Fixing target name.

PLIST_SRC=		PLIST.common

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-sctp
.endif

.include "options.mk"

PLIST_SRC+=		PLIST.common_end

.include "Makefile.versions"

post-install:
	chmod -R go-w ${PREFIX}/lib/erlang/lib/kernel-${VERSION.kernel}/examples
	chmod -R go-w ${PREFIX}/lib/erlang/lib/ssl-${VERSION.ssl}/examples
	rm ${PREFIX}/lib/erlang/lib/observer-${VERSION.observer}/priv/bin/*.bat
	rm ${PREFIX}/lib/erlang/lib/webtool-${VERSION.webtool}/priv/bin/*.bat

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
