# $NetBSD: Makefile,v 1.39 2020/05/18 05:23:26 rillig Exp $
#

DISTNAME=	bonnie++-1.97.3
CATEGORIES=	benchmarks
PKGREVISION=	4
MASTER_SITES=	http://www.coker.com.au/bonnie++/experimental/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.coker.com.au/bonnie++/
COMMENT=	Enhanced performance Test of Filesystem I/O

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl:run tee
REPLACE_PERL+=		bon_csv2txt.in

INSTALLATION_DIRS=	bin share/doc/bonnie++ ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

CFLAGS.NetBSD+=		-D_LARGEFILE64_SOURCE=1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bonnie++.8
SUBST_SED.paths=	-e 's,/usr/share/doc/,${PREFIX}/share/doc/,'

# todo: patch bonnie++.8 to point to correct path to readme.html
post-install:
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DESTDIR}${PREFIX}/share/doc/bonnie++/

.PHONY: benchmark
benchmark: build
	cd ${WRKSRC} && ./bonnie++ -u ${ROOT_USER}:${ROOT_GROUP} | ${TEE} bonnie.out

.PHONY: results
results: build
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC:Q}/bonnie.out /tmp/benches/`domainname`/bonnie++.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
