# $NetBSD: Makefile,v 1.29 2006/04/05 23:01:16 jlam Exp $

DISTNAME=	git-4.3.20
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hulubei.net/tudor/git/
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems

GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST

post-extract:
	${CP} ${WRKSRC}/term/.gitrc.ansi ${WRKSRC}/term/.gitrc.cons25

.include "../../mk/bsd.pkg.mk"
