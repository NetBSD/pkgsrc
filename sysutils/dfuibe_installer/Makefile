# $NetBSD: Makefile,v 1.6 2007/07/16 21:50:12 joerg Exp $
#

DISTNAME=	dfuibe_installer-1.1.7
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pkgsrc-box.org/bsdinstaller/distfiles/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI BSD Installer backend

USE_LIBTOOL=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	msgfmt
MAKE_ENV+=	LOCALEDIR=${PREFIX:Q}/${PKGLOCALEDIR:Q}/locale

SUBST_CLASSES+=	tools
SUBST_STAGE.tools=	pre-configure
SUBST_MESSAGE.tools=	Fixing references to tools
SUBST_FILES.tools=	conf/cmdnames.conf
SUBST_VARS.tools=	REL_PKG_TOOLS_BIN

REL_PKG_TOOLS_BIN=	${PKG_TOOLS_BIN:S/\///}

.include "../../devel/libaura/buildlink3.mk"
.include "../../devel/libdfui/buildlink3.mk"
.include "../../devel/libinstaller/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
