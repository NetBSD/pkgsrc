# $NetBSD: Makefile,v 1.14 2012/10/31 11:17:07 asau Exp $
#

PKGNAME=	jam-2.5.2
DISTNAME=	ft${PKGNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/}
#MASTER_SITES=	ftp://ftp.perforce.com/pub/jam/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://freetype.sourceforge.net/jam/index.html
#HOMEPAGE=	http://www.perforce.com/jam/jam.html
COMMENT=	Program construction tool, like make(1)

CONFLICTS=	acunia-jam-[0-9]*

GNU_CONFIGURE=	yes

USE_TOOLS+=	yacc gmake

DOCDIR=		share/doc/${PKGBASE}
HTMLDIR=	share/doc/html/${PKGBASE}

INSTALLATION_DIRS=	bin ${DOCDIR} ${HTMLDIR}

do-install:
	for f in jam mkjambase; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin.*/$${f} \
			${DESTDIR}${PREFIX}/bin; \
	done

	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${DOCDIR}
	for f in Porting README RELNOTES; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} \
			${DESTDIR}${PREFIX}/${DOCDIR}; \
	done

	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDIR}
	for f in *.html; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} \
			${DESTDIR}${PREFIX}/${HTMLDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
