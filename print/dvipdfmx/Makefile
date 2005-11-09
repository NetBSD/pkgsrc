# $NetBSD: Makefile,v 1.15 2005/11/09 00:22:39 tonio Exp $

DISTNAME=	dvipdfmx-20031116
PKGNAME=	${DISTNAME:S/-/-0.0.0./}
PKGREVISION=	3
CATEGORIES=	print converters
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/release/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/dvipdfmx/
COMMENT=	Dvi to pdf converter with CID-keyed font support

DEPENDS+=	adobe-cmaps-[0-9]*:../../fonts/adobe-cmaps

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*

USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

GNU_CONFIGURE=		YES
#CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX}

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
