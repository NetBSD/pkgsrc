# $NetBSD: Makefile,v 1.61 2005/04/27 16:15:24 christos Exp $

DISTNAME=	cku211
PKGNAME=	kermit-8.0.211
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.columbia.edu/kermit/
COMMENT=	Network and serial communication, file transfer, and scripting utility

LICENSE=	kermit-license

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
BUILD_DEFS+=	KERMIT_SUID_UUCP KFLAGS LIBS MANINSTALL
MAKE_ENV+=	KFLAGS="${KFLAGS}" LIBS="${LIBS}"
MAKE_ENV+=	SSLINC="${SSLINC}" SSLLIB="${SSLLIB}"
MAKEFILE=	makefile
PLIST_SRC=	${WRKDIR}/PLIST

#KFLAGS+=	-DNODEBUG -DNOOLDMODEMS

# Set to empty
SSLINC=		-I${WRKDIR}/.buildlink/include
SSLLIB=		-L${WRKDIR}/.buildlink/lib ${COMPILER_RPATH_FLAG}${WRKDIR}/.buildlink/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${PREFIX}/bin/kermit
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kermit
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/kermit
	for OPT in ${MANINSTALL} broken-solaris-needs-this; do \
	  case $$OPT in \
	    catinstall) \
		nroff -man ${WRKSRC}/ckuker.nr > ${WRKSRC}/kermit.0; \
		${INSTALL_MAN} ${WRKSRC}/kermit.0 ${PREFIX}/man/cat1/kermit.0; \
		${ECHO} man/cat1/kermit.0 >>${PLIST_SRC}; \
		;; \
	    maninstall) \
		${INSTALL_MAN} ${WRKSRC}/ckuker.nr ${PREFIX}/man/man1/kermit.1; \
		${ECHO} man/man1/kermit.1 >>${PLIST_SRC}; \
		;; \
	  esac; \
	done

.if defined(KERMIT_SUID_UUCP)
.if ${KERMIT_SUID_UUCP} == "yes" || ${KERMIT_SUID_UUCP} == "YES"
BINOWN=		uucp
BINMODE=	4555
.endif
.endif

.for __tmp__ in NetBSD-1.3*
.if ${MACHINE_PLATFORM:M${__tmp__}} != ""
LIBS+=          -ltermcap
.endif
.endfor

# XXX This needs to be tested. XXX
#
# Include SOCKS firewall support
.if defined(USE_SOCKS)
.if ${USE_SOCKS} == 4
KFLAGS+=	-DSOCKS
LIBS+=		-L${PREFIX}/lib -lsocks4
.include "../../net/socks4/buildlink3.mk"
.elif ${USE_SOCKS} == 5
KFLAGS+=	-DSOCKS -DCK_SOCKS5
LIBS+=		-L${PREFIX}/lib -lsocks5
.include "../../net/socks5/buildlink3.mk"
.endif
.endif

.if ${OPSYS} == "Darwin"
BUILD_TARGET=	macosx10
.elif ${OPSYS} == "Linux"
BUILD_TARGET=	linux
.else
BUILD_TARGET=	netbsd+openssl
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
