# $NetBSD: Makefile,v 1.72 2014/05/08 10:35:58 rodent Exp $
#

PKGNAME=	url2pkg-2.19
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/creating.html
COMMENT=	Tool to automate initial steps in building a package
LICENSE=	original-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run
AUTO_MKDIRS=	yes

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
	${INSTALL_SCRIPT} ${WRKSRC}/url2pkg.pl ${DESTDIR}${PREFIX}/bin/url2pkg
	${INSTALL_MAN} ${FILESDIR}/url2pkg.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/MakeMaker.pm ${DESTDIR}${PREFIX}/lib/url2pkg/ExtUtils/

.include "../../mk/bsd.pkg.mk"
