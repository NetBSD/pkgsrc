# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:15 tv Exp $
#

PKGREVISION=	1

.include "Makefile.common"

COMMENT=	GNUstep Workspace manager

pre-install:
	${CP} ${FILESDIR}/GNUmakefile ${WRKSRC}/GWLib

.include "../../sysutils/GWLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
