# $NetBSD: Makefile,v 1.12 1998/06/22 12:52:32 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1996/11/21 11:54:39 asami Exp
#

DISTNAME=	git-4.3.17
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	YES
INFO_FILES=	git.info

pre-install:
	(cd ${WRKSRC}/info ; ${MAKE} info )
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25
	(cd ${WRKSRC}/term ; ${PATCH} --quiet -p0 <${FILESDIR}/gitrc.cons25.patch )

post-install:
	${MKDIR} ${PREFIX}/share/doc
	${MV} ${PREFIX}/lib/git/html ${PREFIX}/share/doc/git

.include "../../mk/bsd.pkg.mk"
