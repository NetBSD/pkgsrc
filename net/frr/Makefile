# $NetBSD: Makefile,v 1.11 2022/06/28 11:34:59 wiz Exp $

GITHUB_PROJECT=	frr
VERSION=	8.2.2
GITHUB_TAG=	frr-${VERSION}
DISTNAME=	frr-${VERSION}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=FRRouting/}

MAINTAINER=	kardel@NetBSD.org
HOMEPAGE=	https://github.com/FRRouting/frr/
COMMENT=	Frr routing multi protocol suite
LICENSE=	gnu-gpl-v2

CONFLICTS=	quagga-[0-9]*

WRKSRC=			${WRKDIR}/frr-frr-${VERSION}
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl bash pkg-config autoconf automake autoreconf bison
USE_LIBTOOL=		YES
GNU_CONFIGURE=		yes
BUILD_DEFS=		VARBASE
BISON_REQD=		3.3

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

FRR_GROUP?=	_frr
FRR_VTY_GROUP?=	frrvty

FRR_USER?=		_frr
FRR_CONF_MODE=		0640
FRR_CONFDIR_MODE=	0755
FRR_LOG_MODE=		0640

PKG_SYSCONFDIR_PERMS=	${FRR_USER} ${FRR_VTY_GROUP} ${FRR_CONFDIR_MODE}
PKG_SYSCONFSUBDIR=	frr

PKG_GECOS.${FRR_USER}=	FRRouting User
PKG_HOME.${FRR_USER}=	/nonexistent
PKG_SHELL.${FRR_USER}=	/bin/sh

PKG_GROUPS=	${FRR_GROUP} ${FRR_VTY_GROUP}
PKG_USERS=	${FRR_USER}:${FRR_GROUP}

RCD_SUPPLIED=	bgpd ospf6d ospfd ripd ripngd zebra
RCD_SCRIPTS=	${RCD_SUPPLIED} staticd

.for f in ${RCD_SUPPLIED}
RCD_SCRIPT_SRC.${f}=	${WRKSRC}/pkgsrc/${f}.sh
.endfor

USE_TOOLS+=	bash:run
REPLACE_BASH=	tools/frr.in tools/*.sh.in

REPLACE_PYTHON=	tools/generate_support_bundle.py tools/frr-reload.py tools/frr_babeltrace.py

MESSAGE_SUBST+=		FRR_USER=${FRR_USER}
MESSAGE_SUBST+=		FRR_VTY_GROUP=${FRR_VTY_GROUP}

SUBST_CLASSES+=		ids
SUBST_STAGE.ids=	pre-configure
SUBST_MESSAGE.ids=	Fixing user/group references.
SUBST_FILES.ids=	pkgsrc/zebra.sh.in
SUBST_VARS.ids=		FRR_USER FRR_VTY_GROUP

SUBST_CLASSES+=		workdir
SUBST_STAGE.workdir=	post-configure
SUBST_MESSAGE.workdir=	Fixing absolute workdir references.
SUBST_FILES.workdir=	lib/version.h
SUBST_SED.workdir=	-e "s,${WRKDIR},"'{WRKDIR},g'
SUBST_VARS.workdir=

.if ${OPSYS} == "NetBSD"
# prohibit cluttering NetBSD executables with notes
# that are not recognized by the kernel leading to
# confusing but harmless warning messages
CFLAGS+=		-DFRR_XREF_NO_NOTE
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-user=${FRR_USER}
CONFIGURE_ARGS+=	--enable-group=${FRR_GROUP}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run/frr
CONFIGURE_ARGS+=	--enable-multipath=64
CONFIGURE_ARGS+=	--enable-vty-group=${FRR_VTY_GROUP}
CONFIGURE_ARGS+=	--enable-configfile-mask=${FRR_CONF_MODE}
CONFIGURE_ARGS+=	--enable-logfile-mask=${FRR_LOG_MODE}
CONFIGURE_ARGS+=	--enable-fpm
CONFIGURE_ARGS+=	--with-pkg-git-version
CONFIGURE_ARGS+=	--with-pkg-extra-version=/${DISTNAME}
# CONFIGURE_ARGS+=	--enable-address-sanitizer
CONFIGURE_ARGS+=	--enable-dev-build
pre-configure:
	cd ${WRKSRC} && ${SH} bootstrap.sh

#
# remove dynamically acquired .js files
#
post-build:
	cd ${WRKSRC} && rm -f doc/user/_build/html/_static/jquery-*.js doc/user/_build/html/_static/underscore-*.js

.include "../../devel/libyang2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"

.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
