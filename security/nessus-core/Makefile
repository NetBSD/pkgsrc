# $NetBSD: Makefile,v 1.7 2003/07/13 13:53:11 wiz Exp $
#

DISTNAME=	nessus-core-${VERS}
PKGREVISION=	1
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
