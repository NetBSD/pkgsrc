# $NetBSD: Makefile,v 1.6 2023/10/27 14:15:38 bacon Exp $

DISTNAME=	vsearch-2.24.0
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=torognes/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/torognes/vsearch
COMMENT=	Versatile open-source tool for metagenomics
LICENSE=	gnu-gpl-v3

# Works on powerpc64, but only in little endian mode
ONLY_FOR_PLATFORM=	*-*-aarch64* *-*-powerpc64 *-*-x86_64

USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake autoreconf gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-pdfman

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
