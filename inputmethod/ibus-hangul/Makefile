# $NetBSD: Makefile,v 1.19 2019/05/11 07:19:43 mef Exp $
#

DISTNAME=	ibus-hangul-1.5.0
PKGREVISION=	1
CATEGORIES=	inputmethod korean
MASTER_SITES=	https://github.com/choehwanjin/ibus-hangul/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Hangul engine for IBus input platform
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt intltool

.include "../../lang/python/application.mk"

PLIST_SUBST+=   PYPKGPREFIX_NO=${PYPKGPREFIX:S/py//}

.if !empty(PYPKGPREFIX:Mpy27)
PLIST_SRC=  ${PKGDIR}/PLIST ${PKGDIR}/PLIST.py27
.else
PLIST_SRC=  ${PKGDIR}/PLIST ${PKGDIR}/PLIST.py3
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.1.0
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
