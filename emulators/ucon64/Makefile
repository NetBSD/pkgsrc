# $NetBSD: Makefile,v 1.16 2020/03/20 11:57:36 nia Exp $

DISTNAME=		ucon64-2.2.0-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ucon64/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ucon64.sourceforge.net/
COMMENT=		Emulator ROM and disk image converter and inspector
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME}/src

CONFIGURE_ARGS+=		--with-libcd64
GNU_CONFIGURE=			yes
USE_TOOLS+=			gmake
CHECK_PORTABILITY_SKIP+=	install_beos.sh

INSTALLATION_DIRS=	bin lib share/examples/ucon64 share/doc/ucon64/images

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucon64 ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libdiscmage/discmage.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/[a-z]*.txt \
		${DESTDIR}${PREFIX}/share/examples/ucon64
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.html \
		${DESTDIR}${PREFIX}/share/doc/ucon64
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/images/* \
		${DESTDIR}${PREFIX}/share/doc/ucon64/images

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
