# $NetBSD: Makefile,v 1.16 2005/11/14 17:01:36 minskim Exp $

DISTNAME=	dvipdfmx-20031116
PKGNAME=	${DISTNAME:S/-/-0.0.0./}
PKGREVISION=	4
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

post-install:
	cd ${PKG_LOCALTEXMFPREFIX}/dvipdfm/CMap; \
	for file in ../../../Adobe/Resource/CMap/*; do \
		${LN} -s $$file `${BASENAME} $$file`; \
	done

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
