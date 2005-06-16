# $NetBSD: Makefile,v 1.24 2005/06/16 06:58:01 jlam Exp $

DISTNAME=		stalin-0.9
PKGREVISION=		4
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.nj.nec.com/pub/qobi/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.neci.nj.nec.com/homepages/qobi/software.html
COMMENT=		Aggressively optimizing Scheme compiler

# Only ported to these 4 archs
ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc *-*-alpha *-*-mips

UNLIMIT_RESOURCES=	stacksize datasize

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "sparc")
CFLAGS:=		${CFLAGS:C/-O[0-9]*/-O0/}
.endif

INSTALLATION_DIRS=	bin man/man1

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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
