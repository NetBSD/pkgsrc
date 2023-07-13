# $NetBSD: Makefile,v 1.53 2023/07/13 13:49:17 nia Exp $

DISTNAME=	polkit-121
CATEGORIES=	security
MASTER_SITES=	http://www.freedesktop.org/software/polkit/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/polkit
COMMENT=	Authorization Manager
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4
TOOL_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools
TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

NOT_PAX_MPROTECT_SAFE=	lib/polkit-1/polkitd

WRKSRC=			${WRKDIR}/polkit-v.${PKGVERSION_NOREV}
USE_LANGUAGES=		c c++14
USE_TOOLS+=		msgfmt msgmerge pkg-config perl xgettext

MESON_ARGS+=		-Dman=true

PKGCONFIG_OVERRIDE+=	data/polkit-gobject-1.pc.in
PKGCONFIG_OVERRIDE+=	data/polkit-agent-1.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed
CPPFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS -D__EXTENSIONS__

.include "../../mk/bsd.prefs.mk"

POLKITD_USER?=			polkitd
POLKITD_GROUP?=			polkitd
PKG_GROUPS+=			${POLKITD_GROUP}
PKG_USERS+=			${POLKITD_USER}:${POLKITD_GROUP}
PKG_GECOS.${POLKITD_USER}=	Polkit Daemon User
PKG_HOME.${POLKITD_USER}=	${VARBASE}
PKG_GROUPS_VARS+=		POLKITD_GROUP
PKG_USERS_VARS+=		POLKITD_USER

BUILD_DEFS+=		VARBASE

REPLACE_PERL+=		src/polkitbackend/toarray.pl

INSTALLATION_DIRS+=	share/examples/polkit/polkit-1/rules.d

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/polkit-1/rules.d \
			${POLKITD_USER} ${POLKITD_GROUP} 700
OWN_DIRS_PERMS+=	${PREFIX}/share/polkit-1/rules.d \
			${POLKITD_USER} ${POLKITD_GROUP} 700
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dbus-1/system.d
SPECIAL_PERMS+=		lib/polkit-1/polkit-agent-helper-1 ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=		bin/pkexec ${SETUID_ROOT_PERMS}

CONF_FILES+=	${PREFIX}/share/examples/polkit/polkit-1/rules.d/50-default.rules \
		${PKG_SYSCONFDIR}/polkit-1/rules.d/50-default.rules

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	docs/man/pkexec.xml
SUBST_FILES.paths+=	src/examples/org.freedesktop.policykit.examples.pkexec.policy.in
SUBST_SED.paths+=	-e 's,/usr/bin/,${PREFIX}/bin/,g'

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/polkit-1/rules.d/50-default.rules \
		${DESTDIR}${PREFIX}/share/examples/polkit/polkit-1/rules.d/50-default.rules

.include "../../devel/meson/build.mk"
.include "../../lang/libduktape/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.32
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
