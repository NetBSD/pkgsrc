# $NetBSD: Makefile,v 1.7 2005/06/16 06:57:46 jlam Exp $
#

DISTNAME=	jam-2.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/jam/
EXTRACT_SUFX=	.zip

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.perforce.com/jam/jam.html
COMMENT=	Program construction tool, like make(1)

CONFLICTS=	acunia-jam-[0-9]*

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}

DOCDIR=		share/doc/${PKGBASE}
HTMLDIR=	share/doc/html/${PKGBASE}

INSTALLATION_DIRS=	bin

do-install:
	@for f in jam mkjambase; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin.*/$${f} ${PREFIX}/bin; \
	done

	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	@for f in Porting README RELNOTES; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${DOCDIR}; \
	done

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	@for f in *.html; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${HTMLDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
