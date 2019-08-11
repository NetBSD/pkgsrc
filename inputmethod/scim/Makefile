# $NetBSD: Makefile,v 1.57 2019/08/11 13:21:18 wiz Exp $
#

DISTNAME=		scim-1.4.15
PKGREVISION=		16
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		Smart Common Input Method
LICENSE=		gnu-lgpl-v2.1

SUPERSEDES+=		scim-bridge-[0-9]*

PKG_SYSCONFSUBDIR=	scim

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c gnu++03
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
USE_TOOLS+=		gmake	# make scim-setup.desktop
USE_TOOLS+=		perl intltool
USE_TOOLS+=		autopoint autoconf automake

BUILD_DEPENDS+=		gettext>=0.19.4:../../devel/gettext

PKGCONFIG_OVERRIDE=	scim-gtkutils.pc.in
PKGCONFIG_OVERRIDE+=	scim-x11utils.pc.in
PKGCONFIG_OVERRIDE+=	scim.pc.in

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/scim
CONF_FILES=		${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${EGDIR}/global ${PKG_SYSCONFDIR}/global

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

# for DLOPEN_REQUIRE_PTHREADS
PTHREAD_AUTO_VARS=	yes

CONFIGURE_ENV.NetBSD+=	ac_cv_func_gethostbyname_r=no
CONFIGURE_ENV.SunOS+=	ac_cv_func_gethostbyname_r=no
LDFLAGS.SunOS+=		-lsocket -lnsl

# unused test script
CHECK_PORTABILITY_SKIP+=	extras/immodules/tests/test-exec.sh.in

pre-configure:
	${RUN}cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${SH} bootstrap

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
