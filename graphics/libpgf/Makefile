# $NetBSD: Makefile,v 1.3 2022/07/25 11:12:24 wiz Exp $

DISTNAME=	libpgf-src-6.14.12
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpgf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libpgf.org/
COMMENT=	Progressive Graphics File (PGF) library
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/libpgf
GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

# https://sourceforge.net/p/libpgf/bugs/7/
BUILD_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

pre-patch:
	${CP} ${WRKSRC}/configure.ac ${WRKSRC}/configure.ac.orig
	${CAT} ${WRKSRC}/configure.ac.orig | dos2unix >${WRKSRC}/configure.ac 

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

PKGCONFIG_OVERRIDE+=	libpgf.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
