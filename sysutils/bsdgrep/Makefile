# $NetBSD: Makefile,v 1.1.1.1 2002/11/18 22:33:40 cjep Exp $

DISTNAME=	grep-0.16
PKGNAME=	bsdgrep-0.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.wam.umd.edu/~howardjp/software/grep/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.wam.umd.edu/~howardjp/software/grep/
COMMENT=	BSD version of grep

post-patch:
	@${CP} ${WRKSRC}/grep.1 ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
