# $NetBSD: Makefile,v 1.8 2001/02/25 04:18:11 hubertf Exp $
#

DISTNAME=	teTeX-texmf-1.0.2
PKGNAME=	teTeX-share-1.0.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

DIST_SUBDIR=	teTeX
WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	@${ECHO} ""
	@${ECHO} "Extracting ${DISTFILES} to ${PREFIX}/share/texmf"
	@${ECHO} ""
	@${ECHO} "  ** Get yourself a shower and a big mug of coffee,"
	@${ECHO} "  ** this will take _very_ long!"
	@${ECHO} ""
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	${GTAR} -plzx \
		-C ${PREFIX}/share/texmf \
		-X ${FILESDIR}/exclude \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}

.include "../../mk/bsd.pkg.mk"
