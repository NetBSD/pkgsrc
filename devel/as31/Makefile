# $NetBSD: Makefile,v 1.24 2023/08/10 15:44:24 nia Exp $

DISTNAME=	as31_${PKGVERSION_NOREV}.orig
PKGNAME=	as31-2.3.1
CATEGORIES=	devel
# The actual master site (see HOMEPAGE) uses a strange URL scheme
# that pkgsrc struggles to understand, so use Debian's mirror of
# the original sources.
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/a/as31/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.erazor-zone.de/_media/wiki:projects:linux:as31
COMMENT=	8031/8051 assembler
LICENSE=	modified-bsd # assumed, they say "BSD license"

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	bison
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
