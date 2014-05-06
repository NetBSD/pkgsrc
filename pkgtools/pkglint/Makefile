# $NetBSD: Makefile,v 1.442 2014/05/06 09:32:53 wiz Exp $

# Note: if you update the version number, please have a look at the
# changes between the CVS tag "pkglint_current" and HEAD.
# After updating, please re-set the CVS tag to HEAD.
PKGNAME=	pkglint-4.138
CATEGORIES=	pkgtools

OWNER=		wiz@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Verifier for NetBSD packages
LICENSE=	2-clause-bsd

DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-enum>=1.016:../../devel/p5-enum
DEPENDS+=	p5-pkgsrc-Dewey>=1.0:../../pkgtools/p5-pkgsrc-Dewey

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		pkglint
SUBST_STAGE.pkglint=	post-configure
SUBST_FILES.pkglint+=	build.pl pkglint.pl pkglint.t plist-clash.pl
.if defined(BATCH)
SUBST_SED.pkglint+=	-e s\|@PKGSRCDIR@\|/usr/pkgsrc\|g
.else
SUBST_SED.pkglint+=	-e s\|@PKGSRCDIR@\|${PKGSRCDIR}\|g
.endif
SUBST_SED.pkglint+=	-e s\|@PREFIX@\|${PREFIX}\|g
SUBST_SED.pkglint+=	-e s\|@DISTVER@\|${PKGNAME:S/pkglint-//}\|g
SUBST_SED.pkglint+=	-e s\|@MAKE@\|${MAKE:Q}\|g
SUBST_SED.pkglint+=	-e s\|@PERL@\|${PERL5:Q}\|g
SUBST_SED.pkglint+=	-e s\|@DATADIR@\|${FILESDIR}\|g

SUBST_CLASSES+=		mappaths
SUBST_STAGE.mappaths=	pre-install
SUBST_FILES.mappaths+=	pkglint.pl
SUBST_SED.mappaths+=	-e s\|${FILESDIR}\|${PREFIX}/share/pkglint\|g

do-extract:
	cd ${FILESDIR} && ${CP} build.pl pkglint.0 pkglint.1 pkglint.pl pkglint.t plist-clash.pl ${WRKSRC}
	mkdir ${WRKSRC}/PkgLint
	cd ${FILESDIR} && ${CP} PkgLint/*.pm ${WRKSRC}/PkgLint

do-build:
	cd ${WRKSRC} && ${PERL5} build.pl < pkglint.pl > pkglint.pl.inlined \
		&& mv pkglint.pl.inlined pkglint.pl

do-test:
	cd ${WRKSRC} && prove pkglint.t

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkglint.pl ${DESTDIR}${PREFIX}/bin/pkglint
	${INSTALL_SCRIPT} ${WRKSRC}/plist-clash.pl ${DESTDIR}${PREFIX}/bin/plist-clash
.if !empty(MANINSTALL:Mcatinstall)
.  if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/pkglint.1
.  else
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.  endif
.endif
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif
	${INSTALL_DATA} ${FILESDIR}/makevars.map ${DESTDIR}${PREFIX}/share/pkglint/
	${INSTALL_DATA} ${FILESDIR}/deprecated.map ${DESTDIR}${PREFIX}/share/pkglint/

selftest: .PHONY
	${PREFIX}/bin/pkglint

.include "../../mk/bsd.pkg.mk"
