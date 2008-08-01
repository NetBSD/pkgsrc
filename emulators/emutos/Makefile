# $NetBSD: Makefile,v 1.1 2008/08/01 09:10:58 hauke Exp $

# TODOS
# - hint to this pkg after installing aranym
# - try out hatari pkg with this pkg
# - find out what DESTDIR support is about

DISTNAME=		emutos
PKGNAME=		emutos-0.8.3

CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=emutos/}
DISTFILES=		emutos-512k-0.8.3.zip

MAINTAINER=		hauke@NetBSD.org
HOMEPAGE=		http://emutos.sourceforge.net/
COMMENT=		ROM image of free Atari TOS clone

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		unzip
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/emutos-512k-0.8.3

EMUTOS_DOC_DIR=		${DESTDIR}${PREFIX}/share/doc/${DISTNAME}
EMUTOS_ROM_DIR=		${DESTDIR}${PREFIX}/share/${DISTNAME}

REQD_DIRS+=		${EMUTOS_ROM_DIR:Q} ${EMUTOS_DOC_DIR:Q}

do-install:
	${INSTALL_DATA_DIR} ${EMUTOS_ROM_DIR}
	${INSTALL_DATA} ${WRKSRC}/etos512k.img ${EMUTOS_ROM_DIR}
	${INSTALL_DATA_DIR} ${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/announce.txt ${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/authors.txt ${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/changelog.txt ${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/license.txt ${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/status.txt ${EMUTOS_DOC_DIR}

.include "../../mk/bsd.pkg.mk"
