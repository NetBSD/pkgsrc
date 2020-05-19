# $NetBSD: Makefile,v 1.1 2020/05/19 14:44:04 riastradh Exp $

DISTNAME=	mpfi-1.5.4
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/38111/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gforge.inria.fr/projects/mpfi/
COMMENT=	Multiprecision interval arithmetic library
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	autoconf
USE_TOOLS+=	automake
USE_TOOLS+=	autoreconf
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes

CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
INSTALLATION_DIRS+=	${PKGINFODIR}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

TEST_TARGET=	check

.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
