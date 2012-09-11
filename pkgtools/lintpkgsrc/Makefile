# $NetBSD: Makefile,v 1.9 2012/09/11 23:19:35 asau Exp $

DISTNAME=	lintpkgsrc-4.85
CATEGORIES=	pkgtools
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/Documentation/pkgsrc/
COMMENT=	Sanity checks on the complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest
CONFLICTS+=	pkglint<4.82

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none
AUTO_MKDIRS=	yes

SUBST_CLASSES+=		lp
SUBST_STAGE.lp=		post-configure
SUBST_FILES.lp+=	lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl
.if defined(BATCH)
SUBST_SED.lp+=	-e s\|@PKGSRCDIR@\|/usr/pkgsrc\|g
.else
SUBST_SED.lp+=	-e s\|@PKGSRCDIR@\|${PKGSRCDIR}\|g
.endif
SUBST_SED.lp+=	-e s\|@PREFIX@\|${PREFIX}\|g
SUBST_SED.lp+=	-e s\|@MAKE@\|${MAKE:Q}\|g
SUBST_SED.lp+=	-e s\|@PERL@\|${PERL5:Q}\|g

.include "../../mk/bsd.prefs.mk"

do-extract:
	cd ${FILESDIR} && cp lintpkgsrc.* ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lintpkgsrc.pl ${DESTDIR}${PREFIX}/bin/lintpkgsrc
.if !empty(MANINSTALL:Mcatinstall)
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.endif
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.include "../../mk/bsd.pkg.mk"
