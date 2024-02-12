# $NetBSD: Makefile,v 1.6 2024/02/12 17:10:22 hans Exp $

DISTNAME=	courier-unicode-2.3.0
CATEGORIES=	mail
MASTER_SITES=	https://sourceforge.net/projects/courier/files/courier-unicode/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.courier-mta.org/unicode/
COMMENT=	Implements several algorithms related to the Unicode Standard
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake autoconf aclocal automake
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes

pre-configure:
	(cd ${WRKSRC}; autoconf; aclocal; automake)

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
