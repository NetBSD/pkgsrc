# $NetBSD: Makefile,v 1.21 2000/01/05 23:13:36 tron Exp $
# $FreeBSD Id: Makefile,v 1.17 1997/11/26 23:16:51 jseger Exp
#

DISTNAME=	cku196
PKGNAME=        kermit-7.0.196
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.columbia.edu/kermit/

RESTRICTED=	"'No redistribution' copyright"
NO_CDROM=	${RESTRICTED}
MIRROR_DISTFILE= no

ALL_TARGET=	netbsd
BUILD_DEFS+=	KFLAGS LIBS KERMIT_SUID_UUCP
MAKE_ENV+=	KFLAGS="${KFLAGS}" LIBS="${LIBS}"
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

#KFLAGS+=	-DNODEBUG -DNOOLDMODEMS

# XXX This needs to be tested. XXX
#
# Include SOCKS firewall support
.if defined(USE_SOCKS)
.if ${USE_SOCKS} == 4
DEPENDS+=	socks4-2.2:../../net/socks4
KFLAGS+=	-DSOCKS
LIBS+=		-lsocks
.elif ${USE_SOCKS} == 5
DEPENDS+=	socks5-1.0.2:../../net/socks5
KFLAGS+=	-DSOCKS -DCK_SOCKS5
LIBS+=		-lsocks
.endif
.endif

PLIST_SRC=		${WRKDIR}/PLIST

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${PREFIX}/bin/kermit
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	for OPT in ${MANINSTALL} x; do \
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

.include "../../mk/bsd.pkg.mk"

.if defined(KERMIT_SUID_UUCP)
.if ${KERMIT_SUID_UUCP} == "yes" || ${KERMIT_SUID_UUCP} == "YES"
BINOWN=			uucp
BINMODE=		4555
.endif
.endif
