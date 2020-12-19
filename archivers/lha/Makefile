# $NetBSD: Makefile,v 1.43 2020/12/19 18:02:03 rhialto Exp $

DISTNAME=	lha-1.14i-ac20201220
PKGNAME=	lha-114.9.20201220
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=jca02266/}
GITHUB_PROJECT=	lha
GITHUB_TAG=	50937c3b5dcb0f4234f9a4e3bfa7ae06d40af654

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jca02266/lha
COMMENT=	Archive files using LZW compression (.lzh, .lha files)
LICENSE=	lha-license

CONFIGURE_ARGS+=	--disable-multibyte-filename

RESTRICTED=		Other than for-free distribution of the unmodified \
			source over a network, redistribution terms are complex.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	autoconf automake autoreconf gmake
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf --install --symlink

.include "../../mk/bsd.pkg.mk"
