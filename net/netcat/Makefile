# $NetBSD: Makefile,v 1.13 2003/11/23 01:23:58 jlam Exp $

DISTNAME=	nc110
PKGNAME=	netcat-1.10
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	ftp://coast.cs.purdue.edu/pub/tools/unix/netutils/netcat/ \
		ftp://zippy.telcom.arizona.edu/pub/mirrors/avian.org/hacks/ \
		ftp://ftp.sterling.com/mirrors/avian.org/src/hacks/ \
		ftp://ftp.rge.com/pub/security/coast/mirrors/avian.org/netcat/ \
		ftp://ftp.gw.com/pub/unix/netcat/ \
		ftp://avian.org/src/hacks/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.atstake.com/research/tools/network_utilities/
COMMENT=	Read and write data across network connections

USE_BUILDLINK2=	yes
MAKE_ENV+=	DFLAGS="-DGAPING_SECURITY_HOLE -DTELNET"
ALL_TARGET=	${LOWER_OPSYS}

EXTRA_PROGS=	data rservice xor
EXAMPLE_DIR=	share/examples/nc

PLIST_SRC=	${PKGDIR}/PLIST ${WRKSRC}/data/PLIST.data

post-build:
	@cd ${WRKSRC}/data && ${SETENV} ${MAKE_ENV} ${MAKE} ${EXTRA_PROGS}

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
	${INSTALL_MAN} ${FILESDIR}/nc.1 ${PREFIX}/man/man1/nc.1

.include "../../mk/bsd.pkg.mk"
