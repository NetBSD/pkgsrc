# $NetBSD: Makefile,v 1.4 2003/07/13 13:53:18 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=	1

COMMENT=	GNUstep Workspace manager

pre-install:
	${CP} ${FILESDIR}/GNUmakefile ${WRKSRC}/GWLib

.include "../../sysutils/GWLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
