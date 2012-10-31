# $NetBSD: Makefile,v 1.15 2012/10/31 11:16:33 asau Exp $
#

DISTNAME=	acunia-jam-1.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the program construction tool, like make(1)

CONFLICTS=	jam-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/jam
USE_TOOLS+=	yacc

DOCDIR=		share/doc/${PKGBASE}
HTMLDIR=	share/doc/html/${PKGBASE}

INSTALLATION_DIRS=	bin

do-install:
	for file in jam mkjambase; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin.*/$${file} \
			${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${DOCDIR}
	for file in Porting README RELNOTES; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} \
			${DESTDIR}${PREFIX}/${DOCDIR}; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDIR}
	for file in ${WRKSRC}/*.html; do \
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/${HTMLDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
