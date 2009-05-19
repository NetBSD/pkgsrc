# $NetBSD: Makefile,v 1.74 2009/05/19 08:59:06 wiz Exp $

DISTNAME=	cku211
PKGNAME=	kermit-8.0.211
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.columbia.edu/kermit/
COMMENT=	Network and serial communication, file transfer, and scripting utility
LICENSE=	kermit-license

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
BUILD_DEFS+=	KFLAGS LIBS MANINSTALL
MAKE_ENV+=	KFLAGS=${KFLAGS:Q} LIBS=${LIBS:Q}
MAKE_ENV+=	SSLINC=${SSLINC:Q} SSLLIB=${SSLLIB:Q}
MAKE_FILE=	makefile

#KFLAGS+=	-DNODEBUG -DNOOLDMODEMS

# Set to empty
SSLINC=		-I${WRKDIR}/.buildlink/include
SSLLIB=		-L${WRKDIR}/.buildlink/lib ${COMPILER_RPATH_FLAG}${WRKDIR}/.buildlink/lib

.include "options.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/kermit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${DESTDIR}${PREFIX}/bin/kermit
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/kermit.1; \

.for p in NetBSD-1.3*
.  if ${MACHINE_PLATFORM:M${p}} != ""
LIBS+=		-ltermcap
.  endif
.endfor

.if ${OPSYS} == "Darwin"
.  if empty(OS_VERSION:M[0-6]\.*)
BUILD_TARGET=	macosx103
.  else
BUILD_TARGET=	macosx10
.  endif
.elif ${OPSYS} == "Linux"
BUILD_TARGET=	linux
.else
BUILD_TARGET=	netbsd+openssl
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
