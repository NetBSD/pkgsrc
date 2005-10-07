# $NetBSD: Makefile,v 1.27 2005/10/07 12:16:52 rillig Exp $

DISTNAME=	nc110
PKGNAME=	netcat-1.10
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://coast.cs.purdue.edu/pub/tools/unix/netutils/netcat/ \
		ftp://zippy.telcom.arizona.edu/pub/mirrors/avian.org/hacks/ \
		ftp://ftp.sterling.com/mirrors/avian.org/src/hacks/ \
		ftp://ftp.rge.com/pub/security/coast/mirrors/avian.org/netcat/ \
		ftp://avian.org/src/hacks/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.securityfocus.com/tools/137
COMMENT=	Read and write data across network connections

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
MAKE_ENV+=	DFLAGS="-DGAPING_SECURITY_HOLE -DTELNET"

.include "../../mk/bsd.prefs.mk"

NC_TARGET.${OPSYS}?=	${LOWER_OPSYS}
NC_TARGET.IRIX=		irix
NC_TARGET.Interix=	netbsd
NC_TARGET.OpenBSD=	netbsd
NC_TARGET.DragonFly=	freebsd
NC_TARGET.Darwin=	generic
BUILD_TARGET=		${NC_TARGET.${OPSYS}}

EXTRA_PROGS=	data rservice xor
EXAMPLE_DIR=	share/examples/nc

PLIST_SRC=	${PKGDIR}/PLIST ${WRKSRC}/data/PLIST.data

INSTALLATION_DIRS=	man/man1 sbin

post-build:
	@cd ${WRKSRC}/data && ${SETENV} ${MAKE_ENV} ${MAKE} ${EXTRA_PROGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nc ${PREFIX}/sbin
.for i in ${EXTRA_PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/data/${i} ${PREFIX}/sbin/nc-${i}
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
