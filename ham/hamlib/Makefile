# $NetBSD: Makefile,v 1.54 2022/06/28 11:34:08 wiz Exp $
#

DISTNAME=	hamlib-${VERSION}
# V.rcN, VrcN, V~rcN
VERSION=	4.3.1
VERSIOND=	${VERSION}
VERSIONF=	${VERSION}
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	https://github.com/Hamlib/Hamlib/releases/download/${VERSIOND}/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}
WRKSRC=		${WRKDIR}/hamlib-${VERSIONF}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://hamlib.sourceforge.net/
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

# Reported to upstream mailinglist 20210915
post-install:
	mv ${DESTDIR}/${PREFIX}/bin/testlibusb ${DESTDIR}/${PREFIX}/bin/rigctl_testlibusb


TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
