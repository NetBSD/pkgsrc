# $NetBSD: Makefile,v 1.5 2000/03/06 22:15:03 tron Exp $
#

DISTNAME=	teTeX-texmf-1.0.2
PKGNAME=	teTeX-share-1.0.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	hubertf@netbsd.org

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
	${MKDIR} ${PREFIX}/share/texmf
	${GTAR} -plzx \
		-C ${PREFIX}/share/texmf \
		-X ${FILESDIR}/exclude \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}

.include "../../mk/bsd.pkg.mk"
