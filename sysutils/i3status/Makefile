# $NetBSD: Makefile,v 1.10 2019/07/22 23:04:31 wiz Exp $

DISTNAME=	i3status-2.13
CATEGORIES=	sysutils
MASTER_SITES=	https://i3wm.org/i3status/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://i3wm.org/i3status/
COMMENT=	Small program for generating a status bar
LICENSE=	modified-bsd

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	share/examples/${PKGBASE}

CONF_FILES=	${PREFIX}/share/examples/${PKGBASE}/i3status.conf ${PKG_SYSCONFDIR}/i3status.conf

BUILD_DEFS+=	VARBASE

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		i3status.conf
SUBST_SED.fix-paths+=		-e 's,/var,${VARBASE},g'

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/i3status.conf ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "OpenBSD" && ${OPSYS} != "DragonFly"
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
