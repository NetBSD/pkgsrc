# $NetBSD: Makefile,v 1.27 2006/01/26 17:58:18 reed Exp $

DISTNAME=	git-4.3.20
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=git/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hulubei.net/tudor/git/
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems

GNU_CONFIGURE=	YES
INFO_FILES=	git.info git.info-1 git.info-2 git.info-3

post-extract:
	${CP} ${WRKSRC}/term/.gitrc.ansi ${WRKSRC}/term/.gitrc.cons25

.include "../../mk/bsd.pkg.mk"
