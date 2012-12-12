# $NetBSD: Makefile,v 1.62 2012/12/12 12:35:21 wiz Exp $

DISTNAME=	minicom-2.6.1
CATEGORIES=	comms
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3700/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/projects/minicom/
COMMENT=	MS-DOS Telix serial communication program "workalike"
LICENSE=	gnu-gpl-v2

DEPENDS+=	gkermit-[0-9]*:../../comms/gkermit
DEPENDS+=	lrzsz-[0-9]*:../../comms/lrzsz

PKG_INSTALLATION_TYPES=	overwrite pkgviews
INSTALLATION_DIRS=	share/examples/minicom

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	minicom
EGDIR=			${PREFIX}/share/examples/minicom

PKG_GROUPS=		${DIALER_GROUP}
PKG_USERS=		${UUCP_USER}:${UUCP_GROUP}
PKG_GROUPS_VARS+=	DIALER_GROUP UUCP_GROUP
PKG_USERS_VARS=		UUCP_USER

SPECIAL_PERMS=		${PREFIX}/bin/minicom ${UUCP_USER} ${DIALER_GROUP} 4555
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR} ${UUCP_USER} ${DIALER_GROUP} 0755

EVAL_PREFIX+=		GKERMIT_PREFIX=gkermit
EVAL_PREFIX+=		LRZSZ_PREFIX=lrzsz

SUBST_CLASSES+=		minicom
SUBST_MESSAGE.minicom=	Fixing hardcoded paths.
SUBST_STAGE.minicom=	post-patch
SUBST_FILES.minicom=	src/rwconf.c
SUBST_VARS.minicom=	PREFIX GKERMIT_PREFIX LRZSZ_PREFIX

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
