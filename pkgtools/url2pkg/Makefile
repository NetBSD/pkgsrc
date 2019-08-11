# $NetBSD: Makefile,v 1.92 2019/08/11 13:22:37 wiz Exp $

PKGNAME=	url2pkg-2.30
PKGREVISION=	1
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/creating.html
COMMENT=	Tool to automate initial steps in building a package
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run
AUTO_MKDIRS=	yes

do-extract:
	cd ${FILESDIR} && cp *.pl *.pm ${WRKSRC}/

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		up
SUBST_STAGE.up=		do-configure
SUBST_MESSAGE.up=	Replacing variable placeholders
SUBST_FILES.up=		url2pkg.pl MakeMaker.pm
SUBST_VARS.up=		MAKE
SUBST_SED.up+=		-e 's,@PERL@,${PERL5},g'
SUBST_SED.up+=		-e 's,@PERLLIBDIR@,${PREFIX}/lib/url2pkg,g'
.if defined(BATCH)
SUBST_SED.up+=		-e 's,@PKGSRCDIR@,/usr/pkgsrc,g'
.else
SUBST_VARS.up+=		PKGSRCDIR
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/url2pkg.pl ${DESTDIR}${PREFIX}/bin/url2pkg
	${INSTALL_MAN} ${FILESDIR}/url2pkg.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/MakeMaker.pm ${DESTDIR}${PREFIX}/lib/url2pkg/ExtUtils/

.include "../../mk/bsd.pkg.mk"
