# $NetBSD: Makefile,v 1.31 2025/07/18 16:19:44 schmonz Exp $

DISTNAME=	cln-1.3.7
CATEGORIES=	math
MASTER_SITES=	${HOMEPAGE}
MASTER_SITES+=	ftp://ftpthep.physik.uni-mainz.de/pub/gnu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.ginac.de/CLN/
COMMENT=	Class Library for Numbers
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	cln.pc.in
INFO_FILES=		yes
TEST_TARGET=		check

# Work around broken configure test
CONFIGURE_ENV.SunOS+=	cl_cv_proto_perror=yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
