# $NetBSD: Makefile,v 1.30 2009/06/09 21:31:04 minskim Exp $

DISTNAME=	dvipdfmx-20070518
PKGNAME=	${DISTNAME:S/-/-0.0.0./}
PKGREVISION=	2
CATEGORIES=	print converters
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/release/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/dvipdfmx/
COMMENT=	Dvi to pdf converter with CID-keyed font support

DEPENDS+=	adobe-cmaps>=20060615:../../fonts/adobe-cmaps

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*

USE_DIRS+=		texmf-1.4
USE_TOOLS+=		gs:run
GNU_CONFIGURE=		YES
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PREFIX:Q}/share/texmf-dist

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../print/dvipdfmx/map.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"

post-install:
	cd ${PREFIX}/share/texmf-dist/dvipdfm; \
	for file in ../../Adobe/Resource/CMap/*; do \
		${LN} -sf $$file `${BASENAME} $$file`; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dvipdfmx
	${MV} ${PREFIX}/share/texmf-dist/dvipdfm/dvipdfmx.cfg \
		${PREFIX}/share/examples/dvipdfmx/

.include "../../mk/bsd.pkg.mk"
