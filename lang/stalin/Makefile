# $NetBSD: Makefile,v 1.36 2012/10/02 20:11:54 asau Exp $

DISTNAME=		stalin-0.9
PKGREVISION=		5
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.ecn.purdue.edu/qobi/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cobweb.ecn.purdue.edu/~qobi/software.html
#HOMEPAGE+=		https://github.com/barak/stalin
COMMENT=		Aggressively optimizing Scheme compiler

# Only ported to these 4 archs
ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc *-*-alpha *-*-mips
NOT_FOR_BULK_PLATFORM=	SunOS-*-*

UNLIMIT_RESOURCES=	stacksize datasize

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "sparc")
CFLAGS:=		${CFLAGS:C/-O[0-9]*/-O0/}
.endif
CPPFLAGS+=		-I${BUILDLINK_PREFIX.boehm-gc}/include/gc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-patch:
	${SED} -e 's:@PREFIX@:${PREFIX}:g'			\
		-e 's:@LOCALBASE@:${LOCALBASE}:g'		\
		-e 's:@X11BASE@:${X11BASE}:g'			\
	${FILESDIR}/stalin.sh > ${WRKSRC}/stalin.sh

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/lib/stalin
	${INSTALL_PROGRAM} ${WRKSRC}/stalin ${DESTDIR}${PREFIX}/lib/stalin
	${INSTALL_SCRIPT} ${WRKSRC}/stalin.sh ${DESTDIR}${PREFIX}/bin/stalin
	${INSTALL_DATA} ${WRKSRC}/include/*.sc ${DESTDIR}${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/libstalin.a ${DESTDIR}${PREFIX}/lib/stalin
	${INSTALL_MAN} ${WRKSRC}/stalin.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/stalin
	cd ${WRKSRC} && ${INSTALL_DATA} ANNOUNCEMENT COPYING README	\
		stalin.el ${DESTDIR}${PREFIX}/share/doc/stalin/

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
