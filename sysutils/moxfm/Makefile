# $NetBSD: Makefile,v 1.1 2025/04/11 01:49:10 nia Exp $

DISTNAME=	moxfm-1.0.1
CATEGORIES=	sysutils x11
MASTER_SITES=	https://www.musikinformatik.uni-mainz.de/ag/xfm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/19970712063334/http://sugra.desy.de/user/mai/moxfm/
COMMENT=	Motif file manager
LICENSE=	gnu-gpl-v2

USE_IMAKE=	yes

FORCE_C_STD=	gnu89

# NetBSD does not have statfs().
CPPFLAGS.NetBSD+=	-DUSE_STATVFS=1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux" && ${OPSYS} != "SunOS"
CPPFLAGS+=		-DNO_GETMNTENT=1
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/FmMain.c
SUBST_SED.paths=	-e 's,/usr/include/X11,${PREFIX}/lib/X11/moxfm,g'

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
