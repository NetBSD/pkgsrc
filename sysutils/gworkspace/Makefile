# $NetBSD: Makefile,v 1.1.1.1 2002/09/28 02:19:51 rh Exp $
#

.include "Makefile.common"

COMMENT=	GNUstep Workspace manager

pre-install:
	${CP} ${FILESDIR}/GNUmakefile ${WRKSRC}/GWLib

.include "../../sysutils/GWLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
