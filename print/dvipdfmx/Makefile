# $NetBSD: Makefile,v 1.8 2003/12/24 13:02:01 jmmv Exp $

DISTNAME=	dvipdfmx-20021230
PKGNAME=	dvipdfmx-0.0.0.20021230
PKGREVISION=	3
CATEGORIES=	print converters
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/dvipdfmx/
COMMENT=	Dvi to pdf converter with CID-keyed font support

DEPENDS+=	adobe-cmaps-[0-9]*:../../fonts/adobe-cmaps
DEPENDS+=	teTeX-bin>=2.0.2:../../print/teTeX-bin

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

GNU_CONFIGURE=		YES
#CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

post-patch:
		${RM} ${WRKSRC}/data/config/*.orig

.include "../../security/openssl/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
