# $NetBSD: Makefile,v 1.20 2012/09/11 22:37:14 asau Exp $

DISTNAME=		paranoia
PKGNAME=		paranoia-960101
CATEGORIES=		benchmarks
MASTER_SITES=		${MASTER_SITE_NETLIB:=paranoia/}
EXTRACT_SUFX=		.c

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Highly paranoid test of IEEE 754 conformance

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -ffloat-store -o paranoia paranoia.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/paranoia ${DESTDIR}${PREFIX}/bin

benchmark:
	@(cd ${WRKSRC}; ./paranoia < ${FILESDIR}/paranoia.run | tee paranoia.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/paranoia.out /tmp/benches/`domainname`/paranoia.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
