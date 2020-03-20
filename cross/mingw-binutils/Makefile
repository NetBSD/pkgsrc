# $NetBSD: Makefile,v 1.9 2020/03/20 11:57:25 nia Exp $

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
USE_TOOLS+=		pax
INFO_FILES=		yes

BUILDLINK_TRANSFORM+=	rm:-Werror

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
