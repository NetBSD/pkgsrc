# $NetBSD: Makefile,v 1.24 2013/02/27 16:09:27 jperkin Exp $

DISTNAME=	cln-1.3.2
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.ginac.de/CLN/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ginac.de/CLN/
COMMENT=	CLN Class Library for Numbers
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	cln.pc.in
INFO_FILES=		yes
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Work around broken configure test
CONFIGURE_ENV+=		cl_cv_proto_perror=yes
.endif

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
