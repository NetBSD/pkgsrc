# $NetBSD: Makefile,v 1.2 2012/10/06 14:25:17 asau Exp $
#

DISTNAME=	${PKGNAME:S/pl/-/}
PKGNAME=	scim-tables-vietnamese-ext-0.5.6pl17
CATEGORIES=	inputmethod
MASTER_SITES=	http://scim-tables-vietnamese-ext.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/scim-tables-vietnamese-ext/
COMMENT=	Scim table for Telex/VNI Vietnamese Input Method
LICENSE=	gnu-gpl-v2 OR artistic # ${PERL_LICENSE}

DEPENDS+=	scim-tables-[0-9]*:../../inputmethod/scim-tables

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LANGUAGES=	# none

BUILD_TARGET=	compile-telex compile-vni

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e 's|/usr|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
