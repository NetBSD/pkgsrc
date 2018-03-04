# $NetBSD: Makefile,v 1.11 2018/03/04 15:20:02 wiz Exp $

DISTNAME=		ucon64-2.1.0-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ucon64/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ucon64.sourceforge.net/
COMMENT=		Emulator ROM and disk image converter and inspector
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME}/src

CONFIGURE_ARGS+=	--disable-dload
CPPFLAGS+=		-D__unix__
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CHECK_PORTABILITY_SKIP+=install_beos.sh

INSTALLATION_DIRS=	bin share/examples/ucon64 share/doc/ucon64/images

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucon64 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/[a-z]*.txt \
		${DESTDIR}${PREFIX}/share/examples/ucon64
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.html \
		${DESTDIR}${PREFIX}/share/doc/ucon64
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/images/* \
		${DESTDIR}${PREFIX}/share/doc/ucon64/images

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
