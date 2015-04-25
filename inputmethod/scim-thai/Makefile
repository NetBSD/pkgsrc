# $NetBSD: Makefile,v 1.28 2015/04/25 14:23:25 tnn Exp $
#

DISTNAME=	scim-thai-0.1.3
PKGREVISION=	4
CATEGORIES=	inputmethod
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/ \
		ftp://linux.thai.net/pub/ThaiLinux/software/libthai/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/scim-thai
COMMENT=	SCIM IMEngine module for Thai
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libthai/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
