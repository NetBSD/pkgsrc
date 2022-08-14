# $NetBSD: Makefile,v 1.53 2022/08/14 13:13:52 rillig Exp $

PKGNAME=	lintpkgsrc-2022.08.13
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Sanity checks on the complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest
TEST_DEPENDS+=	p5-File-Slurp>=0:../../devel/p5-File-Slurp
TEST_DEPENDS+=	p5-IO-Null>=0:../../devel/p5-IO-Null

USE_TOOLS+=	perl:run
PERL5_REQD+=	5.36

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
AUTO_MKDIRS=	yes

SUBST_CLASSES+=		lp
SUBST_STAGE.lp=		post-configure
SUBST_FILES.lp+=	lintpkgsrc.1 lintpkgsrc.pl
SUBST_VARS.lp+=		MAKE
SUBST_VARS.lp+=		MAKECONF
SUBST_VARS.lp+=		PERL5
SUBST_VARS.lp+=		PKGSRCDIR
SUBST_VARS.lp+=		PKG_INFO
SUBST_VARS.lp+=		PREFIX
SUBST_VARS.lp+=		X11BASE

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
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.include "../../mk/bsd.pkg.mk"
