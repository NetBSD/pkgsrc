# $NetBSD: Makefile,v 1.46 2006/12/06 01:00:41 rillig Exp $
#

DISTNAME=	url2pkg-2.2
CATEGORIES=	pkgtools
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/Documentation/pkgsrc/creating.html
COMMENT=	Tool to automate initial steps in building a package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 lib/url2pkg/ExtUtils

do-extract:
	cd ${FILESDIR} && cp *.pl *.pm ${WRKSRC}/

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		up
SUBST_STAGE.up=		do-configure
SUBST_FILES.up=		url2pkg.pl MakeMaker.pm
SUBST_SED.up=		-e 's,@MAKE@,'${MAKE:Q}',g'
SUBST_SED.up+=		-e 's,@PERL@,${PERL5},g'
SUBST_SED.up+=		-e 's,@PERLLIBDIR@,${PREFIX}/lib/url2pkg,g'
.if defined(BATCH)
SUBST_SED.up+=		-e 's,@PKGSRCDIR@,/usr/pkgsrc,g'
.else
SUBST_SED.up+=		-e 's,@PKGSRCDIR@,${PKGSRCDIR},g'
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/url2pkg.pl ${PREFIX}/bin/url2pkg
	${INSTALL_MAN} ${FILESDIR}/url2pkg.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/MakeMaker.pm ${PREFIX}/lib/url2pkg/ExtUtils/

.include "../../mk/bsd.pkg.mk"
