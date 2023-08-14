# $NetBSD: Makefile,v 1.64 2023/08/14 05:24:39 wiz Exp $
#

VERSION=	4.5.5
DISTNAME=	hamlib-${VERSION}
PKGREVISION=	1
CATEGORIES=	ham
# hamlib is both at github and sourceforge, and upstream documents
# that github is the canonical location.
MASTER_SITES=	${MASTER_SITE_GITHUB:=Hamlib/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://hamlib.github.io/
COMMENT=	API for digital communications equipment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# \todo Consider language bindings.
CONFIGURE_ARGS+=	--without-tcl-binding \
			--without-perl-binding \
			--without-python-binding

CHECK_PORTABILITY_SKIP+=	scripts/build-w64-jtsdk.sh

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
