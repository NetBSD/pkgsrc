# $NetBSD: Makefile,v 1.1 2018/06/11 23:55:50 youri Exp $

DISTNAME=	accountsservice-0.6.42
CATEGORIES=	sysutils
MASTER_SITES=	http://www.freedesktop.org/software/accountsservice/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/software/accountsservice/
COMMENT=	Set of D-Bus interfaces for accessing account information
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake autoconf autoreconf automake

EGDIR=		${PREFIX}/share/examples/accountsservice

CONFIGURE_ARGS+=	--disable-systemd \
			--sysconfdir=${EGDIR}

LDFLAGS.NetBSD+=	-lutil # pw_getpwconf

ALL_ENV+=	EGDIR=${EGDIR}

PKGCONFIG_OVERRIDE+=	src/libaccountsservice/accountsservice.pc.in

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d

CONF_FILES+=	${EGDIR}/dbus-1/system.d/org.freedesktop.Accounts.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.Accounts.conf

SUBST_CLASSES+=		gdm
SUBST_FILES.gdm=	src/daemon.c
SUBST_STAGE.gdm=	post-patch
SUBST_SED.gdm=		-e 's,/etc/gdm/custom.conf,${PKG_SYSCONFDIR}/gdm/custom.conf,g'

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
