# $NetBSD: Makefile,v 1.5 2012/10/09 17:32:33 marino Exp $

DISTNAME=	binutils-2.18
PKGNAME=	mingw-${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mingw.sourceforge.net/
COMMENT=	GNU binutils for win32 cross-development

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_TOOLS+=		pax
INFO_FILES=		yes

BUILDLINK_TRANSFORM+=	rm:-Werror

post-install:
.for f in windres dllwrap
	${LN} -fs ${PREFIX}/bin/${MINGW_TARGET}-${f} \
                ${DESTDIR}${PREFIX}/${MINGW_TARGET}/bin/${f}
.endfor

.include "../../cross/mingw/Makefile.common"
.include "../../cross/mingw-w32api-bin/buildlink3.mk"
.include "../../cross/mingw-runtime-bin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
