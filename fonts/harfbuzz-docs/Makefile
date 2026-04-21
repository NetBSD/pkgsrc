# $NetBSD: Makefile,v 1.1 2026/04/21 20:53:11 wiz Exp $

.include "../../fonts/harfbuzz/Makefile.common"

PKGNAME=	${DISTNAME:S/^harfbuzz-/harfbuzz-docs-/1}
COMMENT=	OpenType text shaping engine (API docs)

TOOL_DEPENDS+=	gtk-doc>=1.32nb9:../../textproc/gtk-doc

MESON_ARGS+=	-Ddocs=enabled
MESON_ARGS+=	-Dutilities=disabled
MESON_ARGS+=	-Dtests=disabled
MESON_ARGS+=	-Dbenchmark=disabled

# conflicts with doc option of older harfbuzz packages
CONFLICTS+=	harfbuzz<14.2.0nb1

# XXX: find a way to only build the docs
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/include
	${RM} -rf ${DESTDIR}${PREFIX}/lib
	${RM} -rf ${DESTDIR}${PREFIX}/share/gir-1.0

.include "../../mk/bsd.pkg.mk"
