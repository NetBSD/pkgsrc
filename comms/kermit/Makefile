# $NetBSD: Makefile,v 1.17 1999/12/20 12:33:45 fredb Exp $
# $FreeBSD Id: Makefile,v 1.17 1997/11/26 23:16:51 jseger Exp
#

DISTNAME=	cku196src
PKGNAME=        kermit-7.0.196.beta11
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/test/tar/
#MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
#		ftp://ftp.th-darmstadt.de/pub/networking/kermit/

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

KFLAGS+=	-DCK_PCT_BAR -DNODEBUG -DNOOLDMODEMS
KFLAGS+=	-DDYNAMIC -DSUNX25

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

# XXX The man page currently doesn't build for NetBSD XXX
#MANCOMPRESSED_IF_MANZ=	yes
#PLIST_SRC=		${WRKDIR}/PLIST

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${PREFIX}/bin/kermit
#	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
#	@for OPT in ${MANINSTALL} x; do \
#	  case $$OPT in \
#	    catinstall) ${ECHO} man/cat1/kermit.0 >>${PLIST_SRC};; \
#	    maninstall) ${ECHO} man/man1/kermit.1 >>${PLIST_SRC};; \
#	  esac; \
#	done

.include "../../mk/bsd.pkg.mk"

.if defined(KERMIT_SUID_UUCP)
.if ${KERMIT_SUID_UUCP} == "yes" || ${KERMIT_SUID_UUCP} == "YES"
BINOWN=			uucp
BINMODE=		4555
.endif
.endif
