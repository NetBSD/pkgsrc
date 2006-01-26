# $NetBSD: Makefile,v 1.26 2006/01/26 17:00:15 reed Exp $

DISTNAME=	git-4.3.17
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=git/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hulubei.net/tudor/git/
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems

GNU_CONFIGURE=	YES
INFO_FILES=	git.info

BUILD_TARGET=	all info

pre-install:
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25
	(cd ${WRKSRC}/term ; ${PATCH} --quiet -p0 <${FILESDIR}/gitrc.cons25.patch )

.include "../../mk/bsd.pkg.mk"
