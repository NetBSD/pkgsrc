# $NetBSD: Makefile,v 1.425 2013/03/26 15:08:28 schmonz Exp $

# Note: if you update the version number, please have a look at the
# changes between the CVS tag "pkglint_current" and HEAD.
# After updating, please re-set the CVS tag to HEAD.
DISTNAME=	pkglint-4.127
CATEGORIES=	pkgtools
MASTER_SITES=	# none
DISTFILES=	# none

OWNER=		wiz@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Verifier for NetBSD packages

DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-enum>=1.016:../../devel/p5-enum
DEPENDS+=	p5-pkgsrc-Dewey>=1.0:../../pkgtools/p5-pkgsrc-Dewey

BUILD_DEPENDS+=	p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
USE_LANGUAGES=	# none
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
SUBST_SED.pkglint+=	-e s\|@DISTVER@\|${DISTNAME:S/pkglint-//}\|g
SUBST_SED.pkglint+=	-e s\|@MAKE@\|${MAKE:Q}\|g
SUBST_SED.pkglint+=	-e s\|@PERL@\|${PERL5:Q}\|g
SUBST_SED.pkglint+=	-e s\|@DATADIR@\|${PREFIX}/share/pkglint\|g
#SUBST_SED.pkglint+=	-e s\|@DATADIR@\|/usr/pkgsrc/pkgtools/pkglint/files\|g

# Note: This target is only intended for use by the pkglint author.
.PHONY: quick-install
quick-install:
	${RM} -rf ${WRKSRC}
	${MKDIR} ${WRKSRC}
	${MAKE} do-extract subst-pkglint do-build do-install selftest clean

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
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.endif
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif
	${INSTALL_DATA} ${FILESDIR}/makevars.map ${DESTDIR}${PREFIX}/share/pkglint/
	${INSTALL_DATA} ${FILESDIR}/deprecated.map ${DESTDIR}${PREFIX}/share/pkglint/

selftest: .PHONY
	${PREFIX}/bin/pkglint

.include "../../mk/bsd.pkg.mk"
