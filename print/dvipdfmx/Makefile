# $NetBSD: Makefile,v 1.18 2005/11/20 19:14:50 minskim Exp $

DISTNAME=	dvipdfmx-20050627
PKGNAME=	${DISTNAME:S/-/-0.0.0./}
CATEGORIES=	print converters
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/release/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/dvipdfmx/
COMMENT=	Dvi to pdf converter with CID-keyed font support

DEPENDS+=	adobe-cmaps>=20051109:../../fonts/adobe-cmaps

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*

GNU_CONFIGURE=		YES
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX}

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../print/dvipdfmx/map.mk"
.include "../../print/teTeX/module.mk"

post-install:
	cd ${PKG_LOCALTEXMFPREFIX}/dvipdfm/CMap; \
	for file in ../../../Adobe/Resource/CMap/*; do \
		${LN} -s $$file `${BASENAME} $$file`; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dvipdfmx
	${MV} ${PKG_LOCALTEXMFPREFIX}/dvipdfm/config/dvipdfmx.cfg \
		${PREFIX}/share/examples/dvipdfmx/

.include "../../mk/bsd.pkg.mk"
