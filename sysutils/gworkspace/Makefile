# $NetBSD: Makefile,v 1.6 2004/01/23 21:50:48 jmmv Exp $
#

.include "Makefile.common"
PKGREVISION=	4

COMMENT=	GNUstep Workspace manager

pre-install:
	${CP} ${FILESDIR}/GNUmakefile ${WRKSRC}/GWLib

.include "../../sysutils/GWLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
