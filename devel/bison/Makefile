# $NetBSD: Makefile,v 1.49 2004/11/02 17:42:13 sketch Exp $

DISTNAME=		bison-1.875
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		GNU yacc(1) replacement

DEPENDS+=		m4>=1.4:../../devel/m4
BUILD_USES_MSGFMT=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

M4=			${LOCALBASE}/bin/gm4

INFO_FILES=		bison.info

TEST_TARGET=		check

.include "../../mk/compiler.mk"

# quotearg_buffer_restyled() has issues with optimisation
.if !empty(PKGSRC_COMPILER:Msunpro)
BUILDLINK_TRANSFORM+=   rm:-O[0-9]*
.endif

.include "../../mk/bsd.pkg.mk"
