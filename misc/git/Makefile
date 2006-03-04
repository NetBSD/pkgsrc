# $NetBSD: Makefile,v 1.28 2006/03/04 21:30:11 jlam Exp $

DISTNAME=	git-4.3.20
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hulubei.net/tudor/git/
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems

GNU_CONFIGURE=	YES
INFO_FILES=	git.info git.info-1 git.info-2 git.info-3

post-extract:
	${CP} ${WRKSRC}/term/.gitrc.ansi ${WRKSRC}/term/.gitrc.cons25

.include "../../mk/bsd.pkg.mk"
