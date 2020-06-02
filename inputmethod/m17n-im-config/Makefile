# $NetBSD: Makefile,v 1.44 2020/06/02 08:22:45 adam Exp $
#

DISTNAME=	m17n-im-config-0.9.0
PKGREVISION=	39
CATEGORIES=	inputmethod devel
MASTER_SITES=	http://www.m17n.org/m17n-lib-download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.m17n.org/common/im-config/index.html
COMMENT=	Configuration input methods of the m17n library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	m17n-im-config.pc.in

MAKE_JOBS_SAFE=		no

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
