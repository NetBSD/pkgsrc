# $NetBSD: Makefile,v 1.3 2003/06/02 01:16:44 jschauma Exp $

DISTNAME=	grep-0.16
PKGNAME=	bsdgrep-0.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vocito.com/downloads/software/grep/ \
		ftp://ftp.vocito.com/pub/vocito.com/software/grep/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.vocito.com/downloads/software/grep/
COMMENT=	BSD version of grep

post-patch:
	@${CP} ${WRKSRC}/grep.1 ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
