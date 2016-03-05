# $NetBSD: Makefile,v 1.11 2016/03/05 11:27:46 jperkin Exp $
#

DISTNAME=	ucommon-6.3.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=commonc++/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/commoncpp/
COMMENT=	Very light-weight C++ library for deeply embedded applications
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	intltool pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	commoncpp.pc.in
PKGCONFIG_OVERRIDE+=	ucommon.pc.in

.include "options.mk"

LDFLAGS.SunOS+=		-lsocket -lnsl -lintl

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
