# $NetBSD: Makefile,v 1.19 2012/09/11 19:47:02 asau Exp $

DISTNAME=	upx-3.08-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	misc archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=upx/}
EXTRACT_SUFX=	.tar.bz2
# consult src/stub/src/c/Makevars.lzma for the supported LZMA SDK version
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} lzma443${EXTRACT_SUFX}
SITES.lzma443.tar.bz2=	${MASTER_SITE_SOURCEFORGE:=sevenzip/}

MAINTAINER=	fab@gnux.info
HOMEPAGE=	http://upx.sourceforge.net/
COMMENT=	Ultimate packer for executables
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl pod2man pod2html pod2text
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/upx

BUILDLINK_TRANSFORM+=	rm:-mcpu=i686

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,-Map rm:-Wl,upx.map
.endif

post-extract:
	mkdir -p ${WRKSRC}/src/stub/src/c/lzma-sdk
	ln -sf ${WRKDIR}/C ${WRKSRC}/src/stub/src/c/lzma-sdk/C

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		PREFIX=${PREFIX} UCLDIR=${PREFIX} LDLIBDIRS=-L${PREFIX}/lib
	cd ${WRKSRC}/doc && ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upx.out ${DESTDIR}${PREFIX}/bin/upx
	${INSTALL_MAN} ${WRKSRC}/doc/upx.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/upx.doc ${DESTDIR}${PREFIX}/share/doc/upx
	${INSTALL_DATA} ${WRKSRC}/doc/upx.html ${DESTDIR}${PREFIX}/share/doc/upx

.include "../../devel/ucl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
