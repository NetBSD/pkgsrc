# $NetBSD: Makefile,v 1.6 2003/06/09 17:01:25 frueauf Exp $
#

DISTNAME=	nessus-core-${VERS}
WRKSRC=		${WRKDIR}/nessus-core
.include 	"../nessus/Makefile.common"

COMMENT=	Core module of the Nessus Network Security Scanner

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-gtk \
		--with-x \
		--localstatedir=/var

RCD_SCRIPTS=	nessusd

.include "../../security/libnasl/buildlink2.mk"
.include "../../security/nessus-libraries/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
