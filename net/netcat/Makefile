# $NetBSD: Makefile,v 1.2 1999/03/07 00:34:36 kim Exp $

PKGNAME=	netcat-1.10
CATEGORIES=	net
DISTNAME!=	${ECHO} ${PKGNAME} | ${SED} -e 's/netcat-/nc/' -e 's/\.//'
DISTFILES=	${DISTNAME}.tgz
MASTER_SITES=	ftp://zippy.telcom.arizona.edu/pub/mirrors/avian.org/hacks/ \
		ftp://ftp.sterling.com/mirrors/avian.org/src/hacks/ \
		ftp://coast.cs.purdue.edu/pub/tools/unix/netcat/ \
		ftp://ftp.rge.com/pub/security/coast/mirrors/avian.org/netcat/ \
		ftp://ftp.gw.com/pub/unix/netcat/ \
		ftp://avian.org/src/hacks/
WRKSRC=		${WRKDIR}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.avian.org/web1/hak/netcat.html

MAKE_ENV+=	DFLAGS="-DGAPING_SECURITY_HOLE -DTELNET"
ALL_TARGET=	netbsd

EXTRA_PROGS=	data rservice xor
EXAMPLE_DIR=	share/examples/nc

PLIST_SRC=	${PKGDIR}/PLIST ${WRKSRC}/data/PLIST.data

post-build:
	cd ${WRKSRC}/data; ${MAKE} ${EXTRA_PROGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nc ${PREFIX}/sbin
.for i in ${EXTRA_PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/data/$i ${PREFIX}/sbin/nc-$i
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/${EXAMPLE_DIR}
	@(							\
	cd ${WRKSRC}/data;					\
	${RM} -f PLIST.data;					\
	for i in README Makefile *.c *.d;			\
	do							\
	    ${INSTALL_DATA} $$i ${PREFIX}/${EXAMPLE_DIR};	\
	    ${ECHO} ${EXAMPLE_DIR}/$$i >> PLIST.data;		\
	done;							\
	${ECHO} "@dirrm ${EXAMPLE_DIR}" >> PLIST.data;		\
	)

.include "../../mk/bsd.pkg.mk"
