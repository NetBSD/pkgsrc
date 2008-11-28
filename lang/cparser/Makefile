# $NetBSD: Makefile,v 1.1.1.1 2008/11/28 01:17:47 bjs Exp $
#

DISTNAME=	cparser-0.9.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cparser/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cparser.sourceforge.net/
COMMENT=	Recursive descent C99 parser

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

AUTO_MKDIRS=	yes
COPTS?=		-O2

#DBG?=		-g3	# XXX debugging option?

MAKE_ENV+=	LIBTOOL_CFLAGS=-prefer-pic
MAKE_ENV+=	COPTS=${COPTS:Q}

BUILDLINK_TRANSFORM+=	rm:-Werror

do-install:
	${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} ${WRKSRC}/build/cparser \
		${DESTDIR}${PREFIX}/bin/cparser

.include "../../devel/libfirm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
