# $NetBSD: Makefile,v 1.71 2025/05/17 02:12:14 gutteridge Exp $

DISTNAME=	minicom-2.7.1
CATEGORIES=	comms
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/4215/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://salsa.debian.org/minicom-team/minicom
COMMENT=	MS-DOS Telix serial communication program "workalike"
LICENSE=	gnu-gpl-v2

DEPENDS+=	gkermit-[0-9]*:../../comms/gkermit
DEPENDS+=	lrzsz-[0-9]*:../../comms/lrzsz

INSTALLATION_DIRS=	share/examples/minicom

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	minicom
EGDIR=			${PREFIX}/share/examples/minicom

SUBST_CLASSES+=		minicom
SUBST_MESSAGE.minicom=	Fixing hardcoded paths.
SUBST_STAGE.minicom=	pre-configure
SUBST_FILES.minicom=	src/rwconf.c
SUBST_VARS.minicom=	PREFIX

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
