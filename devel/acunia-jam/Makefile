# $NetBSD: Makefile,v 1.7 2004/01/20 12:13:27 agc Exp $
#

DISTNAME=	acunia-jam-1.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	skrll@NetBSD.org
HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the program construction tool, like make(1)

CONFLICTS=	jam-[0-9]*

WRKSRC=		${WRKDIR}/jam
USE_BUILDLINK2=	# defined

DOCDIR=		share/doc/${PKGBASE}
HTMLDIR=	share/doc/html/${PKGBASE}

do-install:
	for file in jam mkjambase; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin.*/$${file} ${PREFIX}/bin; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	for file in Porting README RELNOTES; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} ${PREFIX}/${DOCDIR}; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	for file in ${WRKSRC}/*.html; do \
		${INSTALL_DATA} $${file} ${PREFIX}/${HTMLDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
