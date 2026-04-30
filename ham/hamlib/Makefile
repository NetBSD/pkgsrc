# $NetBSD: Makefile,v 1.72 2026/04/30 12:08:28 gdt Exp $
#

VERSION=	4.7.1
DISTNAME=	hamlib-${VERSION}
CATEGORIES=	ham
# hamlib is both at github and sourceforge, and upstream documents
# that github is the canonical location.
MASTER_SITES=	${MASTER_SITE_GITHUB:=Hamlib/}
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://hamlib.github.io/
COMMENT=	API for digital communications equipment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c11
USE_CXX_FEATURES=	c++11

USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

# \todo Consider language bindings.
CONFIGURE_ARGS+=	--without-tcl-binding \
			--without-perl-binding \
			--without-python-binding

CHECK_PORTABILITY_SKIP+=	scripts/build-w64-jtsdk.sh

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

.include "../../mk/pthread.buildlink3.mk"

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
