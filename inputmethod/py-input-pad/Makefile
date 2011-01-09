# $NetBSD: Makefile,v 1.7 2011/01/09 10:33:02 obache Exp $
#

.include "../../inputmethod/input-pad/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	obache@NetBSD.org
COMMENT=	Python wrapper for Input Pad

PYTHON_VERSIONS_ACCEPTED=	26 25

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
BUILD_DEPENDS+=	swig-[0-9]*:../../devel/swig

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt xgettext msgmerge

PKGCONFIG_OVERRIDE+=	input-pad.pc.in

CONFIGURE_ARGS+=	--enable-python=yes

BUILD_DIRS=		pyinput-pad

post-configure:
	${LN} -s ${BUILDLINK_DIR}/lib/libinput-pad.la ${WRKSRC}/input-pad

PY_PATCHPLIST=		yes

BUILDLINK_API_DEPENDS.input-pad+=	input-pad>=${PKGVERSION_NOREV}
.include "../../inputmethod/input-pad/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
