# $NetBSD: Makefile,v 1.33 2001/11/26 04:52:47 hubertf Exp $
# $FreeBSD Id: Makefile,v 1.17 1997/11/26 23:16:51 jseger Exp
#

DISTNAME=	cku200b04
PKGNAME=        kermit-8.0.200.b4
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/test/tar/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.columbia.edu/kermit/
COMMENT=	Network and serial communication, file transfer, and scripting utility

LICENSE=	kermit-license

ALL_TARGET=	netbsd
BUILD_DEFS+=	KFLAGS LIBS KERMIT_SUID_UUCP
MAKE_ENV+=	KFLAGS="${KFLAGS}" LIBS="${LIBS}"
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}
PLIST_SRC=	${WRKDIR}/PLIST

#KFLAGS+=	-DNODEBUG -DNOOLDMODEMS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${PREFIX}/bin/kermit
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}

no-manpage-in-beta-release:
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

.include "../../mk/bsd.prefs.mk"

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
DEPENDS+=	socks4-2.2:../../net/socks4
KFLAGS+=	-DSOCKS
LIBS+=		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lsocks
.elif ${USE_SOCKS} == 5
DEPENDS+=	socks5-1.0.2:../../net/socks5
KFLAGS+=	-DSOCKS -DCK_SOCKS5
LIBS+=		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lsocks5
.endif
.endif

.include "../../mk/bsd.pkg.mk"
