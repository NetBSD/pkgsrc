# $NetBSD: Makefile,v 1.1.1.1 2007/01/25 19:34:22 drochner Exp $
#

DISTNAME=	mppenc-1.16
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musepack.net/
COMMENT=	Musepack encoder

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

do-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/cmake \
	 -DCMAKE_INSTALL_PREFIX:STRING=${PREFIX})

.include "../../mk/bsd.pkg.mk"
