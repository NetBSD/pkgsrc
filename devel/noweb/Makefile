# $NetBSD: Makefile,v 1.9 1998/06/22 11:27:50 agc Exp $
# FreeBSD Id: Makefile,v 1.10 1997/09/15 07:22:06 tg Exp
#

DISTNAME=	noweb-2.8a
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.virginia.edu/pub/nr/
EXTRACT_SUFX=	.tgz
ONLY_FOR_ARCHS=	i386

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	icont:../../lang/icon
RUN_DEPENDS=	iconx:../../lang/icon

WRKSRC=		${WRKDIR}/src

.include "../../mk/bsd.pkg.mk"
