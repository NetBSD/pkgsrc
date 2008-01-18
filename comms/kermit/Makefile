# $NetBSD: Makefile,v 1.70 2008/01/18 05:06:26 tnn Exp $

DISTNAME=	cku211
PKGNAME=	kermit-8.0.211
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.columbia.edu/kermit/
COMMENT=	Network and serial communication, file transfer, and scripting utility

LICENSE=	kermit-license

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
BUILD_DEFS+=	KFLAGS LIBS MANINSTALL
MAKE_ENV+=	KFLAGS=${KFLAGS:Q} LIBS=${LIBS:Q}
MAKE_ENV+=	SSLINC=${SSLINC:Q} SSLLIB=${SSLLIB:Q}
MAKE_FILE=	makefile
USE_TOOLS+=	nroff

#KFLAGS+=	-DNODEBUG -DNOOLDMODEMS

# Set to empty
SSLINC=		-I${WRKDIR}/.buildlink/include
SSLLIB=		-L${WRKDIR}/.buildlink/lib ${COMPILER_RPATH_FLAG}${WRKDIR}/.buildlink/lib

.if !empty(MANINSTALL:Mcatinstall)
PLIST_SUBST+=	HAVE_CATPAGE=""
.else
PLIST_SUBST+=	HAVE_CATPAGE="@comment "
.endif

.if !empty(MANINSTALL:Mmaninstall)
PLIST_SUBST+=	HAVE_MANPAGE=""
.else
PLIST_SUBST+=	HAVE_MANPAGE="@comment "
.endif

.include "options.mk"

INSTALLATION_DIRS=	bin share/doc/kermit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${PREFIX}/bin/kermit
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/kermit
	set -e; \
	for OPT in ${MANINSTALL} broken-solaris-needs-this; do \
	  case $$OPT in \
	    catinstall) \
		nroff -man ${WRKSRC}/ckuker.nr > ${WRKSRC}/kermit.0; \
		${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/cat1; \
		${INSTALL_MAN} ${WRKSRC}/kermit.0 ${PREFIX}/${PKGMANDIR}/cat1/kermit.0; \
		;; \
	    maninstall) \
		${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man1; \
		${INSTALL_MAN} ${WRKSRC}/ckuker.nr ${PREFIX}/${PKGMANDIR}/man1/kermit.1; \
		;; \
	  esac; \
	done

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
