# $NetBSD: Makefile,v 1.4 2003/07/17 22:54:10 grant Exp $

DISTNAME=	grep-0.16
PKGNAME=	bsdgrep-0.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vocito.com/downloads/software/grep/ \
		ftp://ftp.vocito.com/pub/vocito.com/software/grep/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.vocito.com/downloads/software/grep/
COMMENT=	BSD version of grep

post-patch:
	@${CP} ${WRKSRC}/grep.1 ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
