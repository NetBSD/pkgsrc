# $NetBSD: Makefile,v 1.1.1.1 2010/06/29 07:29:32 manu Exp $
#

DISTNAME=	pam_p11-0.1.5
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/pam_p11/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensc-project.org/files/pam_p11/
COMMENT=	Smart card PAM module
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../security/openssl/buildlink3.mk"
.include "../../security/libp11/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
