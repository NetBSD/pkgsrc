# $NetBSD: Makefile,v 1.7 2021/05/02 11:06:14 nia Exp $

DISTNAME=	accountsservice-0.6.42
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.freedesktop.org/software/accountsservice/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/software/accountsservice/
COMMENT=	Set of D-Bus interfaces for accessing account information
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake autoconf autoreconf automake msgfmt
USE_TOOLS+=	gdbus-codegen

EGDIR=		${PREFIX}/share/examples/accountsservice

CONFIGURE_ARGS+=	--disable-systemd \
			--sysconfdir=${EGDIR}

CONFIGURE_ENV.SunOS+=	ac_cv_have_decl_WTMPX_FILENAME=yes
CPPFLAGS.SunOS+=	-DWTMPX_FILENAME=WTMPX_FILE

LDFLAGS.NetBSD+=	-lutil # pw_getpwconf

ALL_ENV+=	EGDIR=${EGDIR}

PKGCONFIG_OVERRIDE+=	src/libaccountsservice/accountsservice.pc.in

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d

CONF_FILES+=	${EGDIR}/dbus-1/system.d/org.freedesktop.Accounts.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.Accounts.conf

SUBST_CLASSES+=		gdm
SUBST_FILES.gdm=	src/daemon.c
SUBST_STAGE.gdm=	pre-configure
SUBST_SED.gdm=		-e 's,/etc/gdm/custom.conf,${PKG_SYSCONFDIR}/gdm/custom.conf,g'

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
