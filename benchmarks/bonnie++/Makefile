# $NetBSD: Makefile,v 1.21 2008/01/19 09:16:17 wiz Exp $
#

DISTNAME=	bonnie++-1.03a
PKGREVISION=	3
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/bonnie++/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.coker.com.au/bonnie++/
COMMENT=	Enhanced performance Test of Filesystem I/O

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl:run tee
REPLACE_PERL+=		bon_csv2txt.in bon_csv2html.in

INSTALLATION_DIRS=	share/doc/bonnie++

# todo: patch bonnie++.8 to point to correct path to readme.html
post-install:
	${INSTALL_DATA} ${WRKSRC}/readme.html ${PREFIX}/share/doc/bonnie++/

.PHONY: benchmark
benchmark: build
	cd ${WRKSRC} && ./bonnie++ -u ${ROOT_USER}:${ROOT_GROUP} | ${TEE} bonnie.out

.PHONY: results
results: build
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC:Q}/bonnie.out /tmp/benches/`domainname`/bonnie++.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
