# $NetBSD: Makefile,v 1.21 2003/08/03 00:02:44 seb Exp $
# FreeBSD Id: Makefile,v 1.8 1996/11/21 11:54:39 asami Exp
#

DISTNAME=	git-4.3.17
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=git/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.unh.edu/~tudor/git/
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems

GNU_CONFIGURE=	YES
USE_NEW_TEXINFO=	YES
INFO_FILES=	git.info

ALL_TARGET=	all info

pre-install:
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25
	(cd ${WRKSRC}/term ; ${PATCH} --quiet -p0 <${FILESDIR}/gitrc.cons25.patch )

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc
	${MV} ${PREFIX}/lib/git/html ${PREFIX}/share/doc/git

.include "../../mk/bsd.pkg.mk"
