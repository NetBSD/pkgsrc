# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 18:44:24 jlam Exp $
#

DISTNAME=	jam-2.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/jam/
EXTRACT_SUFX=	.tar

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://www.perforce.com/jam/jam.html
COMMENT=	Program construction tool, like make(1)

DOCDIR=		share/doc/${PKGBASE}
HTMLDIR=	share/doc/html/${PKGBASE}

do-install:
	@for file in jam mkjambase; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin.*/$${file} ${PREFIX}/bin; \
	done

	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	@for file in Porting README RELNOTES; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} ${PREFIX}/${DOCDIR}; \
	done

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	@for file in *.html; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} ${PREFIX}/${HTMLDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
