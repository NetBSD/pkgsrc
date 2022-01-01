# $NetBSD: Makefile,v 1.44 2022/01/01 19:02:34 rhialto Exp $

DISTNAME=	lha-1.14i-ac20211125
PKGNAME=	lha-114.9.20211125
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=jca02266/}
GITHUB_PROJECT=	lha
GITHUB_TAG=	72b97b87a131e88cc95b9068d521f3ecb56af9db

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
