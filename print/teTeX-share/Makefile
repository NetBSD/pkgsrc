# $NetBSD: Makefile,v 1.3 1999/08/24 14:21:40 tron Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	teTeX-texmf-1.0
PKGNAME=	teTeX-share-1.0
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
	@${ECHO} "  Get yourself a shower and a big mug of coffee, this "
	@${ECHO} "  will take _very_ long!"
	@${ECHO} ""
	${MKDIR} ${PREFIX}/share/texmf
	${GTAR} plzxCXf ${PREFIX}/share/texmf ${FILESDIR}/exclude \
	  ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}

.include "../../mk/bsd.pkg.mk"
