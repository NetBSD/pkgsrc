# $NetBSD: Makefile,v 1.1.1.1 2004/11/20 16:24:43 minskim Exp $
#

DISTNAME=	dasm212
PKGNAME=	dasm-2.12
CATEGORIES=	cross
MASTER_SITES=	http://members.cox.net/rcolbert/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	mor@linex.com
HOMEPAGE=	http://members.cox.net/rcolbert/dasm.htm
COMMENT=	Multi-CPU cross-assembler for 6502, 6803 and 68HC11

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

MAKEFILE=	${FILESDIR}/Makefile

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.pkg.mk"
