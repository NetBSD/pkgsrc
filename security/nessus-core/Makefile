# $NetBSD: Makefile,v 1.1.1.1 2000/07/30 11:13:09 frueauf Exp $
#

DISTNAME=	nessus-core-${VERS}
.include 	"../nessus/Makefile.common"

DEPENDS+=	nessus-libraries-${VERS}:../nessus-libraries
DEPENDS+=	libnasl-${VERS}:../libnasl
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

WRKSRC=		${WRKDIR}/nessus-core

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-gtk \
		--with-x \
		--localstatedir=/var

.include "../../mk/bsd.pkg.mk"
