# $NetBSD: Makefile,v 1.11 2004/05/03 05:52:55 snj Exp $
#

DISTNAME=	nessus-core-${VERS}
PKGREVISION=	1
.include 	"../nessus/Makefile.common"

COMMENT=	Core module of the Nessus Network Security Scanner

WRKSRC=		${WRKDIR}/nessus-core
USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-gtk \
		--with-x \
		--localstatedir=/var

RCD_SCRIPTS=	nessusd

.include "../../security/libnasl/buildlink3.mk"
.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
