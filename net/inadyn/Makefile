# $NetBSD: Makefile,v 1.19 2023/10/24 22:10:19 wiz Exp $

DISTNAME=	inadyn-2.5
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=troglobit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://troglobit.com/inadyn.html
COMMENT=	Dynamic DNS client
LICENSE=	gnu-gpl-v2

GITHUB_RELEASE=	v2.5
GITHUB_TYPE=	release

USE_TOOLS+=	gmake pkg-config
RCD_SCRIPTS=	inadyn

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-openssl

LIBS.SunOS=	-lsocket -lnsl

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/doc/inadyn

OWN_DIRS+=		${VARBASE}/db/inadyn ${VARBASE}/run

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		etc
SUBST_SED.etc=		-e "s|/etc|${PKG_SYSCONFDIR}|g"
SUBST_FILES.etc=	man/inadyn.conf.5 man/inadyn.8
SUBST_MESSAGE.etc=	Fixing path to configuration file
SUBST_STAGE.etc=	pre-configure

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.inadyn
PKG_SUPPORTED_OPTIONS=	static

.include "../../mk/bsd.options.mk"

##
## Static link
##
.if !empty(PKG_OPTIONS:Mstatic)
LDFLAGS+=	-static
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libite/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
