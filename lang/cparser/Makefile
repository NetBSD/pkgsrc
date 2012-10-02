# $NetBSD: Makefile,v 1.5 2012/10/02 20:11:37 asau Exp $
#

DISTNAME=	cparser-0.9.9
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cparser/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cparser.sourceforge.net/
COMMENT=	Recursive descent C99 parser

NO_CONFIGURE=	yes

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

COPTS?=		-O2

#DBG?=		-g3	# XXX debugging option (install without strip)

MAKE_ENV+=	LIBTOOL_CFLAGS=-prefer-pic
MAKE_ENV+=	COPTS=${COPTS:Q}

BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} ${WRKSRC}/build/cparser \
		${DESTDIR}${PREFIX}/bin/cparser
	${INSTALL_MAN} ${WRKSRC}/cparser.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libfirm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
