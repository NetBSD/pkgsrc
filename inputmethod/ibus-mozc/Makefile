# $NetBSD: Makefile,v 1.94 2024/05/29 16:33:10 adam Exp $

PKGNAME=	ibus-${DISTNAME}
PKGREVISION=	2

INSTALLATION_DIRS+=	libexec share/ibus share/ibus/component \
			share/ibus-mozc

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	mozc-renderer>=2.29:../../inputmethod/mozc-renderer
DEPENDS+=	mozc-server>=2.29:../../inputmethod/mozc-server
DEPENDS+=	mozc-tool>=2.29:../../inputmethod/mozc-tool

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/bazel \
			--output_user_root=${WRKDIR}/bazel \
			--client_debug \
			build \
			unix/ibus:ibus_mozc unix/icons \
			--host_action_env=CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR} \
			--action_env=CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR} \
			--host_action_env=PATH=${PATH} \
			--action_env=PATH=${PATH} \
			--sandbox_debug \
			--verbose_failures \
			--subcommands \
			--config oss_linux --compilation_mode opt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bazel-out/${OSDEST}/bin/unix/ibus/ibus_mozc \
		${DESTDIR}${PREFIX}/libexec/ibus-engine-mozc
	${INSTALL_DATA} ${WRKSRC}/bazel-out/${OSDEST}/bin/unix/ibus/mozc.xml \
		${DESTDIR}${PREFIX}/share/ibus/component/mozc.xml
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DESTDIR}${PREFIX}/share/ibus-mozc/product_icon.png

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/mozc-server/Makefile.common"
.include "../../mk/bsd.pkg.mk"
