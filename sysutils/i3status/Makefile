# $NetBSD: Makefile,v 1.24 2022/07/02 16:53:35 ryoon Exp $

DISTNAME=	i3status-2.14
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://i3wm.org/i3status/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://i3wm.org/i3status/
COMMENT=	Small program for generating a status bar
LICENSE=	modified-bsd

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_TOOLS+=	pkg-config bash perl

INSTALLATION_DIRS=	share/examples/${PKGBASE}

CONF_FILES=	${PREFIX}/share/examples/${PKGBASE}/i3status.conf \
		${PKG_SYSCONFDIR}/i3status.conf

BUILD_DEFS+=	VARBASE

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		man/i3status.*
SUBST_SED.fix-paths+=		-e 's,/var,${VARBASE},g'

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
