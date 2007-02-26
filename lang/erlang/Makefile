# $NetBSD: Makefile,v 1.28 2007/02/26 15:47:43 joerg Exp $

DISTNAME=		otp_src_${DIST_VERSION}
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

.include "options.mk"

PLIST_SRC+=		PLIST.common_end

.include "Makefile.versions"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
