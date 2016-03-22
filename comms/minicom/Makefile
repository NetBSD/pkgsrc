# $NetBSD: Makefile,v 1.68 2016/03/22 23:24:10 ryoon Exp $

DISTNAME=	minicom-2.7
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://alioth.debian.org/frs/download.php/file/3977/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/projects/minicom/
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
SUBST_STAGE.minicom=	post-patch
SUBST_FILES.minicom=	src/rwconf.c
SUBST_VARS.minicom=	PREFIX

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
