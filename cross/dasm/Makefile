# $NetBSD: Makefile,v 1.2 2004/11/22 02:10:45 minskim Exp $
#

DISTNAME=	dasm212
PKGNAME=	dasm-2.12
CATEGORIES=	cross
MASTER_SITES=	http://members.cox.net/rcolbert/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	xmor61@users.sourceforge.net
HOMEPAGE=	http://members.cox.net/rcolbert/dasm.htm
COMMENT=	Multi-CPU cross-assembler for 6502, 6803 and 68HC11

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

MAKEFILE=	${FILESDIR}/Makefile

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.pkg.mk"
