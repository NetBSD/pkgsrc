# $NetBSD: Makefile,v 1.6 2020/03/20 11:57:54 nia Exp $
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

CONFIGURE_ARGS+=	--with-zinnia-convert=${LOCALBASE}/bin/zinnia_convert

.include "../../mk/bsd.pkg.mk"
