# $NetBSD: Makefile,v 1.19 2004/04/28 05:06:28 snj Exp $

DISTNAME=		stalin-0.9
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.nj.nec.com/pub/qobi/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.neci.nj.nec.com/homepages/qobi/software.html
COMMENT=		Aggressively optimizing Scheme compiler

# Only ported to these 4 archs
ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc *-*-alpha *-*-mips

USE_BUILDLINK3=		yes
USE_X11=		yes
UNLIMIT_RESOURCES=	stacksize datasize

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "sparc")
CFLAGS:=		${CFLAGS:C/-O[0-9]*/-O0/}
.endif

post-patch:
	${SED} -e 's:@PREFIX@:${PREFIX}:g'			\
		-e 's:@LOCALBASE@:${LOCALBASE}:g'		\
		-e 's:@X11BASE@:${X11BASE}:g'			\
	${FILESDIR}/stalin.sh > ${WRKSRC}/stalin.sh

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/stalin
	${INSTALL_PROGRAM} ${WRKSRC}/stalin ${PREFIX}/lib/stalin
	${INSTALL_SCRIPT} ${WRKSRC}/stalin.sh ${PREFIX}/bin/stalin
	${INSTALL_DATA} ${WRKSRC}/include/*.sc ${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/libstalin.a ${PREFIX}/lib/stalin
	${INSTALL_MAN} ${WRKSRC}/stalin.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/stalin
	cd ${WRKSRC} && ${INSTALL_DATA} ANNOUNCEMENT COPYING README	\
		stalin.el ${PREFIX}/share/doc/stalin/

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
