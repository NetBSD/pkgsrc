# $NetBSD: Makefile,v 1.4 2003/07/21 17:16:20 martti Exp $

DISTNAME=	dvipdfmx-20021230
PKGNAME=	dvipdfmx-0.0.0.20021230
PKGREVISION=	1
CATEGORIES=	print converters
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/dvipdfmx/
COMMENT=	Dvi to pdf converter with CID-keyed font support

DEPENDS+=	adobe-cmaps-[0-9]*:../../fonts/adobe-cmaps
DEPENDS+=	teTeX2-bin>=2.0.2:../../print/teTeX2-bin

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
#CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

post-patch:
		${RM} ${WRKSRC}/data/config/*.orig

.include "../../security/openssl/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../print/teTeX2-bin/kpathsea.buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
