# $NetBSD: Makefile,v 1.2 2006/02/05 23:09:05 joerg Exp $
#

DISTNAME=		ucon64-2.0.0-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ucon64/}

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://ucon64.sourceforge.net/
COMMENT=		Emulator ROM and disk image converter and inspector

WRKSRC=			${WRKDIR}/${DISTNAME}/src

CONFIGURE_ARGS+=	--disable-discmage # requires some work
CONFIGURE_ARGS+=	--disable-dload
CPPFLAGS+=		-D__unix__
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucon64 ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ucon64
	${INSTALL_DATA} ${WRKSRC}/[a-z]*.txt ${PREFIX}/share/examples/ucon64/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ucon64 \
		${PREFIX}/share/doc/ucon64/images
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.html \
		${PREFIX}/share/doc/ucon64/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/images/* \
		${PREFIX}/share/doc/ucon64/images/

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
