# $NetBSD: Makefile,v 1.2 1998/12/30 18:00:03 tron Exp $
# FreeBSD Id: Makefile,v 1.7 1998/08/31 07:51:40 tg Exp
#

DISTNAME=	rtf2LaTeX.1.5
PKGNAME=	rtf2latex-1.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dante.de/pub/tex/support/rtf2latex/

MAINTAINER=	tron@netbsd.org

WRKSRC=		${WRKDIR}/rtf2LaTeX
NO_PATCH=	yes
NO_CONFIGURE=	yes

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include <../../mk/bsd.pkg.mk>
