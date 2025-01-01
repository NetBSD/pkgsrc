# $NetBSD: Makefile,v 1.32 2025/01/01 08:11:18 jmmv Exp $

DISTNAME=	sysbuild-2.8
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/jmmv/sysbuild/releases/download/sysbuild-2.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Automates builds of NetBSD and manages source trees
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

PKG_SYSCONFSUBDIR=	sysbuild
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	SYSBUILD_CONFSUBDIR=
INSTALL_MAKE_FLAGS+=	sysbuild_confdir=${EGDIR}
EGDIR=			${PREFIX}/share/examples/sysbuild
CONF_FILES+=		${EGDIR}/default.conf ${PKG_SYSCONFDIR}/default.conf

BUILDLINK_API_DEPENDS.shtk+=	shtk>=1.7
.include "../../devel/shtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
