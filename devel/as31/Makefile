# $NetBSD: Makefile,v 1.23 2023/08/10 15:39:36 nia Exp $

DISTNAME=	as31_${PKGVERSION_NOREV}.orig
PKGNAME=	as31-2.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/a/as31/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.erazor-zone.de/_media/wiki:projects:linux:as31
COMMENT=	8031/8051 assembler
LICENSE=	modified-bsd # assumed, they say "BSD license"

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	bison
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
