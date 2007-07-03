# $NetBSD: Makefile,v 1.9 2007/07/03 13:54:45 joerg Exp $
#

DISTNAME=	spamdyke-2.6.3
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.spamdyke.org/
COMMENT=	Monitors and intercept incoming SMTP connections to qmail

BUILD_DIRS=	${PKGBASE} utils

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${PKGBASE}/spamdyke.h
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_SED.paths+=	-e 's,@QMAILDIR@,${QMAILDIR:Q},g'
SUBST_STAGE.paths=	do-configure

BUILD_DEFS+=		QMAILDIR

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

.include "options.mk"

do-install:
	cd ${WRKSRC}/${PKGBASE};					\
	for f in spamdyke; do						\
		${INSTALL_PROGRAM} $${f} ${PREFIX}/bin;			\
	done
	cd ${WRKSRC}/utils;						\
	for f in dnsmx dnsptr dnstxt passwordcheck; do			\
		${INSTALL_PROGRAM} $${f} ${PREFIX}/bin/spamdyke-$${f};	\
	done;								\
	for f in domain2path domainsplit; do				\
		${INSTALL_PROGRAM} $${f} ${PREFIX}/bin;			\
	done
	cd ${WRKSRC}/documentation;					\
	for f in *.txt; do						\
		${INSTALL_DATA} $${f} ${PREFIX}/share/doc/${PKGBASE};	\
	done

.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
