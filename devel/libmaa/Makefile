# $NetBSD: Makefile,v 1.6 2011/10/22 10:01:00 cheusov Exp $

DISTNAME=		libmaa-1.3.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dict/}

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://www.dict.org/
COMMENT=		General purpose data structures and functions
LICENSE=		gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		lib
TEST_TARGET=		test

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGDOCDIR=		${PREFIX}/share/doc/libmaa
INSTALLATION_DIRS+=	${PKGDOCDIR} lib include

EXTRA_DOC_FILES=	COPYING.LIB README doc/libmaa.600dpi.ps

post-install:
.for i in ${EXTRA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
