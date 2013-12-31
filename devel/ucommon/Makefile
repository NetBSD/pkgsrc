# $NetBSD: Makefile,v 1.4 2013/12/31 14:42:13 rodent Exp $
#

DISTNAME=	ucommon-6.0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=commonc++/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/commoncpp/
COMMENT=	Very light-weight C++ library for deeply embedded applications
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	intltool pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DINSTALL_MANDIR=${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	commoncpp.pc.in
PKGCONFIG_OVERRIDE+=	ucommon.pc.in

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
