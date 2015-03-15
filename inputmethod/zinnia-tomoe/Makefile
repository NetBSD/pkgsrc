# $NetBSD: Makefile,v 1.3 2015/03/15 19:31:44 hiramatsu Exp $
#

DISTNAME=	zinnia-tomoe-0.6.0-20080911
PKGNAME=	zinnia-tomoe-0.6.0.20080911
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zinnia/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zinnia.sourceforge.net/
COMMENT=	Zinna recognition models traned with Tomoe data
#LICENSE=	# Tomoe's

BUILD_DEPENDS+=	zinnia-[0-9]*:../../inputmethod/zinnia

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

FIND_PREFIX:=	ZINNIA_DIR=zinnia
.include "../../mk/find-prefix.mk"

CONFIGURE_ARGS+=	--with-zinnia-convert=${ZINNIA_DIR}/bin/zinnia_convert

.include "../../mk/bsd.pkg.mk"
