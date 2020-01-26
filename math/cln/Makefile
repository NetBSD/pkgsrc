# $NetBSD: Makefile,v 1.29 2020/01/26 17:31:38 rillig Exp $

DISTNAME=	cln-1.3.4
CATEGORIES=	math
MASTER_SITES=	http://www.ginac.de/CLN/
MASTER_SITES+=	ftp://ftpthep.physik.uni-mainz.de/pub/gnu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.ginac.de/CLN/
COMMENT=	CLN Class Library for Numbers
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
