# $NetBSD: Makefile,v 1.11 2004/04/26 01:30:41 snj Exp $

DISTNAME=	dvipdfmx-20031116
PKGNAME=	${DISTNAME:S/-/-0.0.0./}
PKGREVISION=	1
CATEGORIES=	print converters
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/release/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/dvipdfmx/
COMMENT=	Dvi to pdf converter with CID-keyed font support

DEPENDS+=	adobe-cmaps-[0-9]*:../../fonts/adobe-cmaps
DEPENDS+=	teTeX-bin>=2.0.2:../../print/teTeX-bin

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

GNU_CONFIGURE=		YES
#CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

.include "../../graphics/png/buildlink3.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
