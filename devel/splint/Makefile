# $NetBSD: Makefile,v 1.15 2010/01/27 18:19:27 joerg Exp $
#

DISTNAME=	splint-3.1.2
VERSION=	3.1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.splint.org/downloads/
DISTFILES=	${DISTNAME}.src.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake lex
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/splint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
