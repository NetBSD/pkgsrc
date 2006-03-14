# $NetBSD: Makefile,v 1.335 2006/03/14 14:24:14 rillig Exp $
#

DISTNAME=	pkglint-4.59
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.netbsd.org/Documentation/pkgsrc/
COMMENT=	Verifier for NetBSD packages and complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-pkgsrc-Dewey>=1.0:../../pkgtools/p5-pkgsrc-Dewey

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty

INSTALLATION_DIRS=	bin ${PKGMANDIR:Q}/cat1 ${PKGMANDIR:Q}/man1 share/pkglint

SUBST_CLASSES+=		pkglint
SUBST_STAGE.pkglint=	post-configure
SUBST_FILES.pkglint+=	lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl
SUBST_FILES.pkglint+=	pkglint.0 pkglint.1 pkglint.pl
SUBST_FILES.pkglint+=	plist-clash.pl
.if defined(BATCH)
SUBST_SED.pkglint+=	-e s\|@PKGSRCDIR@\|/usr/pkgsrc\|g
.else
SUBST_SED.pkglint+=	-e s\|@PKGSRCDIR@\|${PKGSRCDIR:Q}\|g
.endif
SUBST_SED.pkglint+=	-e s\|@PREFIX@\|${PREFIX:Q}\|g
SUBST_SED.pkglint+=	-e s\|@DISTVER@\|${DISTNAME:S/pkglint-//:Q}\|g
SUBST_SED.pkglint+=	-e s\|@MAKE@\|${MAKE:Q}\|g
SUBST_SED.pkglint+=	-e s\|@PERL@\|${PERL5:Q}\|g
SUBST_SED.pkglint+=	-e s\|@DATADIR@\|${PREFIX:Q}/share/pkglint\|g

.include "../../mk/bsd.prefs.mk"

# Note: This target is only intended for use by the pkglint author.
.PHONY: quick-install
quick-install:
	${RM} -rf ${WRKSRC:Q}
	${MKDIR} ${WRKSRC:Q}
	${MAKE} do-extract subst-pkglint do-install post-install

do-extract:
	cd ${FILESDIR:Q} && ${CP} lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl pkglint.0 pkglint.1 pkglint.pl plist-clash.pl ${WRKSRC:Q}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/pkglint.pl ${PREFIX:Q}/bin/pkglint
	${INSTALL_SCRIPT} ${WRKSRC:Q}/lintpkgsrc.pl ${PREFIX:Q}/bin/lintpkgsrc
	${INSTALL_SCRIPT} ${WRKSRC:Q}/plist-clash.pl ${PREFIX:Q}/bin/plist-clash
	${INSTALL_MAN} ${WRKSRC:Q}/lintpkgsrc.0 ${PREFIX:Q}/${PKGMANDIR:Q}/cat1
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC:Q}/lintpkgsrc.1 ${PREFIX:Q}/${PKGMANDIR:Q}/man1
	${INSTALL_MAN} ${WRKSRC:Q}/pkglint.1 ${PREFIX:Q}/${PKGMANDIR:Q}/man1
.endif
	${INSTALL_MAN} ${WRKSRC:Q}/pkglint.0 ${PREFIX:Q}/${PKGMANDIR:Q}/cat1
	${INSTALL_DATA} ${FILESDIR:Q}/makevars.map ${PREFIX:Q}/share/pkglint/
	${INSTALL_DATA} ${FILESDIR:Q}/deprecated.map ${PREFIX:Q}/share/pkglint/

post-install:
	${PREFIX:Q}/bin/pkglint -q 1>&2

.include "../../mk/bsd.pkg.mk"
