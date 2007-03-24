# $NetBSD: Makefile,v 1.1.1.1 2007/03/24 07:39:25 schmonz Exp $
#

DISTNAME=	spamdyke-2.2.1
CATEGORIES=	mail
MASTER_SITES=	http://freesoftware.silence.org/spamdyke/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://freesoftware.silence.org/spamdyke/
COMMENT=	Monitors and intercept incoming SMTP connections to qmail

BUILD_DIRS=	${PKGBASE}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${PKGBASE}/spamdyke.c
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_STAGE.paths=	do-configure

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	cd ${WRKSRC}/${PKGBASE};					\
	for f in spamdyke domain2path domainsplit; do			\
		${INSTALL_PROGRAM} $${f} ${PREFIX}/bin;			\
	done
	cd ${WRKSRC}/documentation;					\
	for f in *.txt; do						\
		${INSTALL_DATA} $${f} ${PREFIX}/share/doc/${PKGBASE};	\
	done

.include "../../mk/bsd.pkg.mk"
