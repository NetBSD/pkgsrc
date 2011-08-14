# $NetBSD: Makefile,v 1.9 2011/08/14 14:52:52 obache Exp $
#

DISTNAME=		system-tools-backends-2.6.1
PKGREVISION=		4
CATEGORIES=		sysutils
MASTER_SITES=		http://system-tools-backends.freedesktop.org/downloads/2.6/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://system-tools-backends.freedesktop.org/
COMMENT=		DBus interface for system configuration

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_OPTIONS_VAR=	PKG_OPTIONS.system-tools-backends
PKG_SUPPORTED_OPTIONS+=	hal
PKG_SUGGESTED_OPTIONS+=	hal
PLIST_VARS+=		hal

.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mhal)
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
PLIST.hal=		yes
.endif

EGDIR=		${PREFIX}/share/examples/system-tools-backends
CONF_FILES+=	${EGDIR}/system-tools-backends.conf ${PKG_SYSCONFDIR}/dbus-1/system.d/system-tools-backends.conf

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

STB_GROUP?=		stb-admin
PKG_GROUPS=		${STB_GROUP}
PKG_GROUPS_VARS+=	STB_GROUP

CONFIGURE_ARGS+=	--with-stb-group=${STB_GROUP}
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--with-dbus-sys=${EGDIR}

DEPENDS+=	p5-XML-Twig>=3.32:../../textproc/p5-XML-Twig
DEPENDS+=	p5-Net-DBus>=0.33.6:../../net/p5-Net-DBus
DEPENDS+=	p5-libwww>=5.820:../../www/p5-libwww
DEPENDS+=	p5-URI>=1.37:../../www/p5-URI

REPLACE_PERL+=	SystemToolsBackends.pl.in
REPLACE_PERL+=	Utils/*.pm

SUBST_CLASSES+= 		gettext-package
SUBST_STAGE.gettext-package=	post-configure
SUBST_FILES.gettext-package=	po/Makefile
SUBST_SED.gettext-package=	-e 's|@GETTEXT_PACKAGE@|system-tools-backends|g'

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
