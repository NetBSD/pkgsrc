# $NetBSD: Makefile,v 1.11 2021/09/26 02:33:14 mef Exp $

DISTNAME=	binutils-2.18
PKGNAME=	mingw-${DISTNAME:S/-src//}
PKGREVISION=	2
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mingw.sourceforge.net/
COMMENT=	GNU binutils for win32 cross-development

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls
USE_TOOLS+=		pax bash
INFO_FILES=		yes

BUILDLINK_TRANSFORM+=	rm:-Werror

SUBST_CLASSES+=		bash
SUBST_FILES.bash=	ld/Makefile.in
SUBST_VARS.bash=	BASH
SUBST_STAGE.bash=	post-configure
SUBST_MESSAGE.bash=	Replace $(SHELL) to bash
SUBST_SED.bash=		-e s,@@BASH@@,${PREFIX}/bin/bash,

INSTALLATION_DIRS+=	cross/bin

post-install:
.for f in windres dllwrap
	${LN} -fs ${PREFIX}/cross/bin/${MINGW_TARGET}-${f} \
                ${DESTDIR}${PREFIX}/cross/${MINGW_TARGET}/bin/${f}
.endfor

.include "../../cross/mingw/Makefile.common"
.include "../../cross/mingw-w32api-bin/buildlink3.mk"
.include "../../cross/mingw-runtime-bin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
