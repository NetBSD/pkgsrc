# $NetBSD: Makefile,v 1.46 2022/08/04 21:55:57 rillig Exp $

PKGNAME=	lintpkgsrc-4.99
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Sanity checks on the complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest
TEST_DEPENDS+=	p5-File-Slurp>=0:../../devel/p5-File-Slurp
TEST_DEPENDS+=	p5-IO-Null>=0:../../devel/p5-IO-Null
CONFLICTS+=	pkglint<4.82

USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
AUTO_MKDIRS=	yes

SUBST_CLASSES+=		lp
SUBST_STAGE.lp=		post-configure
SUBST_FILES.lp+=	lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl
SUBST_SED.lp+=		-e 's;@PKGSRCDIR@;${BATCH:D/usr/pkgsrc:U${PKGSRCDIR}};g'
SUBST_VARS.lp+=		MAKE
SUBST_VARS.lp+=		PERL5
SUBST_VARS.lp+=		PKG_SYSCONFDIR
SUBST_VARS.lp+=		PREFIX

.include "../../mk/bsd.prefs.mk"

do-extract:
	cd ${FILESDIR} && cp -R lintpkgsrc.* t ${WRKSRC}/

do-build:
	# Nothing

do-test:
	${RUN} cd ${WRKSRC}/t;						\
	for test in ./*.t; do						\
		echo "Testing $${test#./}";				\
		perl "$$test";						\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lintpkgsrc.pl ${DESTDIR}${PREFIX}/bin/lintpkgsrc
.if !empty(MANINSTALL:Mcatinstall)
.  if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/lintpkgsrc.1
.  else
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.  endif
.endif
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.include "../../mk/bsd.pkg.mk"
