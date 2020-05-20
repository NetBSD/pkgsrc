# $NetBSD: Makefile,v 1.18 2020/05/20 06:09:05 rillig Exp $

DISTNAME=		Isearch-1.47.01
PKGNAME=		isearch-1.47.01
PKGREVISION=		2
CATEGORIES=		textproc databases
MASTER_SITES=		# http://www.etymon.com/pub/Isearch/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.etymon.com/Isearch/
COMMENT=		Advanced text indexing and searching system

# isearch-1.47.01 doesn't declare the dependencies correctly
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin share/doc/isearch

# string.cxx: In function 'char* transcode(char*, const char**)':
# string.cxx:1215:29: error: array subscript has type 'char' [-Werror=char-subscripts]
#      if (transarray[*obufscan]) {
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

post-install:
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${DESTDIR}${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/doc/DebugFirewall.doc ${DESTDIR}${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DESTDIR}${PREFIX}/share/doc/isearch/

.include "../../mk/bsd.pkg.mk"
