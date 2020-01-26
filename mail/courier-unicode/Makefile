# $NetBSD: Makefile,v 1.5 2020/01/26 17:31:33 rillig Exp $

DISTNAME=	courier-unicode-2.1
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
