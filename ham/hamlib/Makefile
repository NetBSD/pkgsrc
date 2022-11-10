# $NetBSD: Makefile,v 1.57 2022/11/10 12:59:13 gdt Exp $
#

VERSION=	4.5
PKGREVISION=	1
DISTNAME=	hamlib-${VERSION}
CATEGORIES=	ham
# hamlib is both at github and sourceforge.  Upstream is not clear
# about which is primary and which is secondary.  The github-fetchable
# distfile appears broken (or attacked?) as of 2022-11-09.
# mailinglists are at sourceforge.
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}
#MASTER_SITES=	${MASTER_SITE_GITHUB:=Hamlib/}

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
