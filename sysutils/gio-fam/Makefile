# $NetBSD: Makefile,v 1.2 2010/11/17 14:35:32 drochner Exp $
#

.include "../../devel/glib2/Makefile.common"

PKGNAME:=		${PKGNAME:S/glib2/gio-fam/}
CATEGORIES=		sysutils

COMMENT=		FAM backend for GIO, the glib VFS API

NOT_FOR_PLATFORM=	HPUX-*-* OSF1-*-*

FAM_ACCEPTED=		fam gamin
FAM_SERVER=		no

CONFIGURE_ARGS+=	--enable-fam

BUILD_DIRS=		gio/fam
INSTALL_DIRS=		${BUILD_DIRS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
MAKE_FLAGS+=		FAM_LIBS="-lfam -lC"
BUILDLINK_TRANSFORM+=	l:fam:fam:C
.endif

.include "../../devel/glib2/modules.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
