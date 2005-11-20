# $NetBSD: Makefile,v 1.17 2005/11/20 18:51:53 minskim Exp $

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
.include "../../wip-kr/dvipdfmx/map.mk"
.include "../../print/teTeX/module.mk"

post-install:
	cd ${PKG_LOCALTEXMFPREFIX}/dvipdfm/CMap; \
	for file in ../../../Adobe/Resource/CMap/*; do \
		${LN} -s $$file `${BASENAME} $$file`; \
	done
	${MV} ${PKG_LOCALTEXMFPREFIX}/dvipdfm/config/dvipdfmx.cfg \
		${PKG_LOCALTEXMFPREFIX}/dvipdfm/config/dvipdfmx-base.cfg

.include "../../mk/bsd.pkg.mk"
