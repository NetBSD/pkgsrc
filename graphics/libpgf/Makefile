# $NetBSD: Makefile,v 1.5 2023/09/29 18:29:29 nros Exp $

DISTNAME=	libpgf
PKGNAME=	libpgf-7.21.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpgf/libpgf/${PKGVERSION_NOREV}/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libpgf.org/
COMMENT=	Progressive Graphics File (PGF) library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${TOUCH} README && ${SH} autogen.sh

PKGCONFIG_OVERRIDE+=	libpgf.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
