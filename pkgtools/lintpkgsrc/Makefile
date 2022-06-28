# $NetBSD: Makefile,v 1.39 2022/06/28 11:35:24 wiz Exp $

PKGNAME=	lintpkgsrc-4.98
PKGREVISION=	1
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org/Documentation/pkgsrc/
COMMENT=	Sanity checks on the complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest
CONFLICTS+=	pkglint<4.82

USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none
AUTO_MKDIRS=	yes

SUBST_CLASSES+=		lp
SUBST_STAGE.lp=		post-configure
SUBST_FILES.lp+=	lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl
.if defined(BATCH)
SUBST_SED.lp+=		-e 's;@PKGSRCDIR@;/usr/pkgsrc;g'
.else
SUBST_VARS.lp+=		PKGSRCDIR
.endif
SUBST_VARS.lp+=		MAKE
SUBST_VARS.lp+=		PERL5
SUBST_VARS.lp+=		PKG_SYSCONFDIR
SUBST_VARS.lp+=		PREFIX

.include "../../mk/bsd.prefs.mk"

do-extract:
	cd ${FILESDIR} && cp lintpkgsrc.* ${WRKSRC}/

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
