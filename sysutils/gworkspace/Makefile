# $NetBSD: Makefile,v 1.10 2004/11/16 07:58:21 rh Exp $
#

.include "Makefile.common"

COMMENT=	GNUstep Workspace manager

pre-install:
	${CP} ${FILESDIR}/GNUmakefile ${WRKSRC}/GWLib

.include "../../sysutils/GWLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
