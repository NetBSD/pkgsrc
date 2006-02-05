# $NetBSD: Makefile,v 1.3 2006/02/05 23:10:07 joerg Exp $
#

DISTNAME=	autocue-20060129
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	Time-based text formatter, sending output to xcb for pasting

DEPENDS+=	xcb-[0-9]*:../../x11/xcb

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autocue ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/autocue.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
