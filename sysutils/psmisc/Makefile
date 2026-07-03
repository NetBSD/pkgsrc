# $NetBSD: Makefile,v 1.36 2026/07/03 18:49:13 wiz Exp $

DISTNAME=	psmisc-v23.7
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=psmisc/psmisc/-/archive/v${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/psmisc/psmisc
COMMENT=	Miscellaneous procfs tools: killall, pidof, and pstree
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
TOOL_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools

CONFLICTS+=	pstree<=2.16

USE_LANGUAGES=		c
USE_TOOLS+=		autoconf automake autoreconf gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-harden-flags
CONFIGURE_ARGS+=	--disable-statx

PLIST_VARS+=	fuser

# fuser works only on Linux.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
PLIST.fuser=		yes
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv && ${SH} po/update-potfiles

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
