# $NetBSD: Makefile,v 1.5 2004/01/03 18:49:53 reed Exp $
#

.include "Makefile.common"
PKGREVISION=	2

COMMENT=	GNUstep Workspace manager

pre-install:
	${CP} ${FILESDIR}/GNUmakefile ${WRKSRC}/GWLib

.include "../../sysutils/GWLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
