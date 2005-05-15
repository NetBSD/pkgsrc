# $NetBSD: Makefile,v 1.4 2005/05/15 19:12:46 jlam Exp $

DISTNAME=	ppp-lzs-1.2
CATEGORIES=	net
MASTER_SITES=	http://homepages.rya-online.net/plunky/

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://homepages.rya-online.net/plunky/lzs.html
COMMENT=	PPP daemon and LKM with Stac LZS decompression

CONFLICTS+=		ppp-* ppp-mppe-*
ONLY_FOR_PLATFORM= 	NetBSD-*-*

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	NETBSDSRCDIR="${NETBSDSRCDIR}"
MAKE_ENV+=	S="${NETBSDSRCDIR}/sys"
MESSAGE_SUBST+= PREFIX="${PREFIX}"

BUILDLINK_PASSTHRU_DIRS=	${NETBSDSRCDIR}/lib/libpcap

pre-extract:
.if !exists(${NETBSDSRCDIR}/usr.sbin/pppd/Makefile)
	@${ECHO} "This package requires the NetBSD source sets to be installed in"
	@${ECHO} "order to compile, as it patches against the supplied pppd. Please"
	@${ECHO} "place them in ${NETBSDSRCDIR} or set the NETBSDSRCDIR variable"
	@${ECHO} "to their location."
	@${FALSE}
.endif

post-extract:
	@${CP} ${NETBSDSRCDIR}/sys/net/ppp-comp.h ${WRKSRC}/net
	@${CP} ${NETBSDSRCDIR}/usr.sbin/pppd/pppd/*.[ch8] ${WRKSRC}/pppd
	@${CP} ${NETBSDSRCDIR}/usr.sbin/pppd/pppd/Makefile ${WRKSRC}/pppd

do-patch:
	@cd ${WRKSRC};							\
	v=`${SED} -n -e "/^#define.*VERSION.*\"\(.*\)\".*/s//\1/p" pppd/patchlevel.h`;	\
	${ECHO} -n "pppd $${v} sources found, ";			\
	if [ -d $${v} ]; then						\
	    ${ECHO} "patching..";					\
	    ${CAT} $${v}/patch.* | ${PATCH} --quiet;			\
	else								\
	    ${ECHO} "Have no patches for this version, sorry!";		\
	    ${FALSE};							\
	fi

pre-install:
.if !exists(${PREFIX}/lkm)
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lkm
.endif

do-install:
	${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} -m 4555 \
		${WRKSRC}/pppd/pppd ${PREFIX}/sbin/pppd
	${INSTALL_MAN} ${WRKSRC}/pppd/pppd.cat8 ${PREFIX}/man/cat8/pppd.0
	${INSTALL_MAN} ${WRKSRC}/pppd/pppd.8 ${PREFIX}/man/man8/pppd.8
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
		${WRKSRC}/lkm/lzs.o ${PREFIX}/lkm/lzs.o

.include "../../mk/bsd.pkg.mk"
