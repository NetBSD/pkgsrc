# $NetBSD: Makefile,v 1.95 2019/08/18 13:32:21 rillig Exp $

PKGNAME=	url2pkg-2.32
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
	${RUN} cd ${FILESDIR} && cp *.* ${WRKSRC}/

do-test:
	${RUN} cd ${WRKSRC} && env PKGSRCDIR=${PKGSRCDIR} perl -I. url2pkg.t

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		up
SUBST_STAGE.up=		do-configure
SUBST_MESSAGE.up=	Replacing variable placeholders
SUBST_FILES.up=		url2pkg.pl MakeMaker.pm
SUBST_VARS.up=		MAKE PERL5 PYTHONBIN
SUBST_SED.up+=		-e 's,@LIBDIR@,${PREFIX}/lib/url2pkg,g'
.if defined(BATCH)
SUBST_SED.up+=		-e 's,@PKGSRCDIR@,/usr/pkgsrc,g'
.else
SUBST_VARS.up+=		PKGSRCDIR
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/url2pkg.pl ${DESTDIR}${PREFIX}/bin/url2pkg
	${INSTALL_MAN} ${FILESDIR}/url2pkg.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/MakeMaker.pm ${DESTDIR}${PREFIX}/lib/url2pkg/ExtUtils/
	${INSTALL_DATA} ${WRKSRC}/setuptools.py ${DESTDIR}${PREFIX}/lib/url2pkg/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
