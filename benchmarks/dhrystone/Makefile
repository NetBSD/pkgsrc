# $NetBSD: Makefile,v 1.16 2012/09/11 22:37:11 asau Exp $

DISTNAME=		dhry2.1
PKGNAME=		dhrystone-2.1
PKGREVISION=		1
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.planix.com/pub/mirror/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Reinhold Weicker's DHRYSTONE 2.1 integer benchmark

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dry2 ${DESTDIR}${PREFIX}/bin/dry2
	${INSTALL_PROGRAM} ${WRKSRC}/dry2reg ${DESTDIR}${PREFIX}/bin/dry2reg
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/dhrystone
	${INSTALL_DATA} ${WRKSRC}/clarify.doc \
		${DESTDIR}${PREFIX}/share/doc/dhrystone
	${INSTALL_DATA} ${WRKSRC}/Rationale \
		${DESTDIR}${PREFIX}/share/doc/dhrystone

benchmark:
	-@${ECHO} 5000000 | ${WRKSRC}/dry2 | tee ${WRKSRC}/dry.out
	-@${ECHO} 5000000 | ${WRKSRC}/dry2reg | tee -a ${WRKSRC}/dry.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/dry.out /tmp/benches/`domainname`/dhrystone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
