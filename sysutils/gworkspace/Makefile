# $NetBSD: Makefile,v 1.8 2004/04/11 03:20:34 rh Exp $
#

.include "Makefile.common"

COMMENT=	GNUstep Workspace manager

pre-install:
	${CP} ${FILESDIR}/GNUmakefile ${WRKSRC}/GWLib

.include "../../sysutils/GWLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
