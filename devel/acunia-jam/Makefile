# $NetBSD: Makefile,v 1.2 2002/10/30 07:20:44 skrll Exp $
#

DISTNAME=	acunia-jam-1.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the program construction tool, like make(1)

CONFLICTS=	jam-[0-9]*

DOCDIR=		share/doc/${PKGBASE}
HTMLDIR=	share/doc/html/${PKGBASE}

WRKSRC=		${WRKDIR}/jam

do-install:
	for file in jam mkjambase; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin.*/$${file} ${PREFIX}/bin; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	for file in Porting README RELNOTES; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} ${PREFIX}/${DOCDIR}; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	for file in *.html; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} ${PREFIX}/${HTMLDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
