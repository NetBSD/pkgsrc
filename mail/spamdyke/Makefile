# $NetBSD: Makefile,v 1.13 2008/05/28 23:57:27 schmonz Exp $
#

DISTNAME=	spamdyke-3.1.8
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.spamdyke.org/
COMMENT=	Monitors and intercept incoming SMTP connections to qmail

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/${PKGBASE}

GNU_CONFIGURE=	yes
BUILD_TARGET=	${PKGBASE}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	spamdyke.h
SUBST_SED.paths=	-e 's,@LOCALBASE@,${LOCALBASE:Q},g'
SUBST_SED.paths+=	-e 's,@QMAILDIR@,${QMAILDIR:Q},g'
SUBST_STAGE.paths=	do-configure

BUILD_DEFS+=		QMAILDIR

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

.include "options.mk"

do-install:
	cd ${WRKSRC};							\
	for f in spamdyke; do						\
		${INSTALL_PROGRAM} $${f} ${DESTDIR}${PREFIX}/bin;	\
	done;								\
	cd ../documentation;						\
	for f in *.txt *.html; do					\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE};\
	done

.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
