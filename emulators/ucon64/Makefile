# $NetBSD: Makefile,v 1.12 2018/03/07 12:34:55 wiz Exp $

DISTNAME=		ucon64-2.1.0-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		1
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD
MAKE_ENV+=		OSTYPE=netbsd
.endif

INSTALLATION_DIRS=	bin lib share/examples/ucon64 share/doc/ucon64/images

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucon64 ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libdiscmage/libdiscmage.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/[a-z]*.txt \
		${DESTDIR}${PREFIX}/share/examples/ucon64
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.html \
		${DESTDIR}${PREFIX}/share/doc/ucon64
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/images/* \
		${DESTDIR}${PREFIX}/share/doc/ucon64/images

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
