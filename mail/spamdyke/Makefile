# $NetBSD: Makefile,v 1.4 2007/05/07 19:43:43 schmonz Exp $
#

DISTNAME=	spamdyke-2.5.0
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://freesoftware.silence.org/spamdyke/
COMMENT=	Monitors and intercept incoming SMTP connections to qmail

BUILD_DIRS=	${PKGBASE} utils
BUILD_TARGET=	bsd

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${PKGBASE}/spamdyke.c
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_STAGE.paths=	do-configure

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	cd ${WRKSRC}/${PKGBASE};					\
	for f in spamdyke; do						\
		${INSTALL_PROGRAM} $${f} ${PREFIX}/bin;			\
	done
	cd ${WRKSRC}/utils;						\
	for f in dnsmx dnsptr dnstxt; do				\
		${INSTALL_PROGRAM} $${f} ${PREFIX}/bin/spamdyke-$${f};	\
	done;								\
	for f in domain2path domainsplit; do				\
		${INSTALL_PROGRAM} $${f} ${PREFIX}/bin;			\
	done
	cd ${WRKSRC}/documentation;					\
	for f in *.txt; do						\
		${INSTALL_DATA} $${f} ${PREFIX}/share/doc/${PKGBASE};	\
	done

.include "../../mk/bsd.pkg.mk"
