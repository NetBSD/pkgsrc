# $NetBSD: Makefile,v 1.2 2007/04/11 14:50:37 schmonz Exp $
#

DISTNAME=	spamdyke-2.4.0
CATEGORIES=	mail
MASTER_SITES=	http://freesoftware.silence.org/spamdyke/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://freesoftware.silence.org/spamdyke/
COMMENT=	Monitors and intercept incoming SMTP connections to qmail

BUILD_DIRS=	${PKGBASE} utils

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${PKGBASE}/spamdyke.c
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_STAGE.paths=	do-configure

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "OpenBSD"
BUILD_TARGET=	openbsd
.endif

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
