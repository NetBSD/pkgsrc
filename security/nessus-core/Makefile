# $NetBSD: Makefile,v 1.4 2003/03/29 12:42:23 jmmv Exp $
#

DISTNAME=	nessus-core-${VERS}
WRKSRC=		${WRKDIR}/nessus-core
.include 	"../nessus/Makefile.common"

COMMENT=	Core module of the Nessus Network Security Scanner

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-gtk \
		--with-x \
		--localstatedir=/var

.include "../../security/libnasl/buildlink2.mk"
.include "../../security/nessus-libraries/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
