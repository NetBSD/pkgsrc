# $NetBSD: Makefile,v 1.361 2007/04/24 15:32:12 tnn Exp $
#

DISTNAME=	pkglint-4.77
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/Documentation/pkgsrc/
COMMENT=	Verifier for NetBSD packages and complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-enum>=1.016:../../devel/p5-enum
DEPENDS+=	p5-pkgsrc-Dewey>=1.0:../../pkgtools/p5-pkgsrc-Dewey

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS_FROM_PLIST=	yes

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		pkglint
SUBST_STAGE.pkglint=	post-configure
SUBST_FILES.pkglint+=	lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl
SUBST_FILES.pkglint+=	pkglint.pl
SUBST_FILES.pkglint+=	plist-clash.pl
.if defined(BATCH)
SUBST_SED.pkglint+=	-e s\|@PKGSRCDIR@\|/usr/pkgsrc\|g
.else
SUBST_SED.pkglint+=	-e s\|@PKGSRCDIR@\|${PKGSRCDIR}\|g
.endif
SUBST_SED.pkglint+=	-e s\|@PREFIX@\|${PREFIX}\|g
SUBST_SED.pkglint+=	-e s\|@DISTVER@\|${DISTNAME:S/pkglint-//:Q}\|g
SUBST_SED.pkglint+=	-e s\|@MAKE@\|${MAKE:Q}\|g
SUBST_SED.pkglint+=	-e s\|@PERL@\|${PERL5:Q}\|g
SUBST_SED.pkglint+=	-e s\|@DATADIR@\|${PREFIX}/share/pkglint\|g

# Note: This target is only intended for use by the pkglint author.
.PHONY: quick-install
quick-install:
	${RM} -rf ${WRKSRC}
	${MKDIR} ${WRKSRC}
	${MAKE} do-extract subst-pkglint do-install selftest clean

do-extract:
	cd ${FILESDIR} && ${CP} lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl pkglint.0 pkglint.1 pkglint.pl plist-clash.pl ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkglint.pl ${DESTDIR}${PREFIX}/bin/pkglint
	${INSTALL_SCRIPT} ${WRKSRC}/lintpkgsrc.pl ${DESTDIR}${PREFIX}/bin/lintpkgsrc
	${INSTALL_SCRIPT} ${WRKSRC}/plist-clash.pl ${DESTDIR}${PREFIX}/bin/plist-clash
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
	${INSTALL_DATA} ${FILESDIR}/makevars.map ${DESTDIR}${PREFIX}/share/pkglint/
	${INSTALL_DATA} ${FILESDIR}/deprecated.map ${DESTDIR}${PREFIX}/share/pkglint/

selftest: .PHONY
	${LOCALBASE}/bin/pkglint

.include "../../mk/bsd.pkg.mk"
