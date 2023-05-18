# $NetBSD: Makefile,v 1.26 2023/05/18 08:43:20 spz Exp $
#

DISTNAME=		IPMITOOL_1_8_19
PKGNAME=		ipmitool-1.8.19
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=ipmitool/}
GITHUB_PROJECT=		ipmitool
GITHUB_TAG=		IPMITOOL_1_8_19
WRKSRC=			${WRKDIR}/ipmitool-${GITHUB_TAG}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/ipmitool/ipmitool
COMMENT=		Command-line utility for managing IPMI devices
LICENSE=		modified-bsd

USE_TOOLS=		automake autoconf
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
INSTALLATION_DIRS+=	share/examples/ipmitool share/doc/ipmitool

CONFIGURE_ARGS.NetBSD+=		--enable-intf-open --disable-intf-imb
CONFIGURE_ARGS.DragonFly+=	--disable-intf-open --disable-intf-imb
CONFIGURE_ARGS.SunOS+=		--enable-solaris-opt

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

DEPENDS+=		iana-enterprise-numbers-[0-9]*:../../net/iana-enterprise-numbers

pre-configure:
	cd ${WRKSRC} && ./bootstrap

# ipmitool uses rl_event_hook
.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
