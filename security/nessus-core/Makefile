# $NetBSD: Makefile,v 1.9 2004/01/20 12:25:34 agc Exp $
#

DISTNAME=	nessus-core-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Core module of the Nessus Network Security Scanner

WRKSRC=		${WRKDIR}/nessus-core
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
