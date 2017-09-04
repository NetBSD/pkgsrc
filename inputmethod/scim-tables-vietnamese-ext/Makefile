# $NetBSD: Makefile,v 1.4 2017/09/04 18:55:08 wiz Exp $
#

DISTNAME=	${PKGNAME:S/pl/-/}
PKGNAME=	scim-tables-vietnamese-ext-0.5.6pl17
CATEGORIES=	inputmethod
MASTER_SITES=	http://scim-tables-vietnamese-ext.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/scim-tables-vietnamese-ext/
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
