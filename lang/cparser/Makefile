# $NetBSD: Makefile,v 1.11 2026/08/04 20:29:02 wiz Exp $
#

DISTNAME=	cparser-0.9.14
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cparser/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cparser.sourceforge.net/
COMMENT=	Recursive descent C99 parser
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

MAKE_ENV+=	LIBTOOL_CFLAGS=-prefer-pic
MAKE_ENV+=	COPTS=${COPTS:Q}
MAKE_ENV+=	builddir=build variant=optimize

BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} ${WRKSRC}/build/cparser \
		${DESTDIR}${PREFIX}/bin/cparser
	${INSTALL_MAN} ${WRKSRC}/cparser.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/libfirm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
