# $NetBSD: Makefile,v 1.2 2013/04/22 06:03:36 rodent Exp $
#

DISTNAME=	ccrtp-2.0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ccrtp/
COMMENT=	RTP and RTSP protocol implementation using GNU CommonCpp
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libccrtp1.pc.in
INFO_FILES=		yes

.include "options.mk"

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../devel/ucommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
