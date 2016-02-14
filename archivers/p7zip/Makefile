# $NetBSD: Makefile,v 1.60 2016/02/14 08:39:47 ryoon Exp $

DISTNAME=	p7zip_15.09_src_all
PKGNAME=	p7zip-15.09
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=p7zip/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://p7zip.sourceforge.net/
COMMENT=	File archiver with high compression
LICENSE=	gnu-lgpl-v2.1 AND unrar-license

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FILE=		makefile
MAKE_JOBS_SAFE=		no # missing header when compiling sfx
NO_CONFIGURE=		yes
PTHREAD_OPTS+=		require
PLIST_VARS=		dll

# compiles, but does not recognize any archives as supported
DYNAMIC_7Z?=		NO
.if !empty(DYNAMIC_7Z:MYES)
BUILD_TARGET=		all2
PLIST.dll=		yes
CFLAGS+=		-fPIC
.endif

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV:S/-/_/}

GCC_REQD+=		3.0

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
.if !empty(DYNAMIC_7Z:MYES)
INSTALLATION_DIRS+=	lib/7z
INSTALLATION_DIRS+=	lib/7z/Codecs
INSTALLATION_DIRS+=	lib/7z/Formats
.endif
INSTALLATION_DIRS+=	share/doc/p7zip
INSTALLATION_DIRS+=	share/doc/p7zip/commands
INSTALLATION_DIRS+=	share/doc/p7zip/switches

SUBST_CLASSES+=		lib
SUBST_FILES.lib+=	CPP/7zip/UI/Common/LoadCodecs.cpp
SUBST_SED.lib+=		-e "s,getenv(.P7ZIP_HOME_DIR.),\"${PREFIX}/lib/\","
SUBST_STAGE.lib=	post-patch

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

.include "../../mk/endian.mk"

.if !empty(MACHINE_ENDIAN:Mbig)
CFLAGS+=		-DBIG_ENDIAN
.else
CFLAGS+=		-DLITTLE_ENDIAN
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/7za ${DESTDIR}${PREFIX}/bin
.if !empty(DYNAMIC_7Z:MYES)
	${INSTALL_LIB} ${WRKSRC}/bin/7z.so ${DESTDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/7z ${DESTDIR}${PREFIX}/lib/7z
	ln -f -s ${PREFIX}/lib/7z/7z ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/bin/Codecs/* \
		${DESTDIR}${PREFIX}/lib/7z/Codecs
.else
	ln -f -s 7za ${DESTDIR}${PREFIX}/bin/7z
.endif
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/p7zip
	${INSTALL_DATA} ${WRKSRC}/DOC/MANUAL/cmdline/*.* \
		${DESTDIR}${PREFIX}/share/doc/p7zip
	${INSTALL_DATA} ${WRKSRC}/DOC/MANUAL/cmdline/commands/*.* \
		${DESTDIR}${PREFIX}/share/doc/p7zip/commands
	${INSTALL_DATA} ${WRKSRC}/DOC/MANUAL/cmdline/switches/*.* \
		${DESTDIR}${PREFIX}/share/doc/p7zip/switches
	${INSTALL_MAN} ${WRKSRC}/man1/7z.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man1/7za.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man1/7zr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
