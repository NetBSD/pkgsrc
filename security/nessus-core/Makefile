# $NetBSD: Makefile,v 1.2 2001/02/17 17:49:54 wiz Exp $
#

DISTNAME=	nessus-core-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Core module of the Nessus Network Security Scanner

DEPENDS+=	nessus-libraries-${VERS}:../nessus-libraries
DEPENDS+=	libnasl-${VERS}:../libnasl
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

WRKSRC=		${WRKDIR}/nessus-core

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-gtk \
		--with-x \
		--localstatedir=/var

.include "../../mk/bsd.pkg.mk"
