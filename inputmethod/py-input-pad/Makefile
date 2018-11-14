# $NetBSD: Makefile,v 1.48 2018/11/14 22:21:52 kleink Exp $

.include "../../inputmethod/input-pad/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python wrapper for Input Pad

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
BUILD_DEPENDS+=	swig-1.[0-9]*:../../devel/swig

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt xgettext msgmerge

PKGCONFIG_OVERRIDE+=	input-pad.pc.in

CONFIGURE_ARGS+=	--enable-pygobject2=yes
CONFIGURE_ARGS+=	--disable-maintainer-mode

BUILD_DIRS=		pyinput-pad

post-configure:
	${LN} -s ${BUILDLINK_DIR}/lib/libinput-pad.la ${WRKSRC}/input-pad

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

BUILDLINK_API_DEPENDS.input-pad+=	input-pad>=${PKGVERSION_NOREV}
.include "../../inputmethod/input-pad/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
