# $NetBSD: Makefile,v 1.1.1.1 1999/09/21 09:57:31 agc Exp $
#

DISTNAME=	qpage-3.2
CATEGORIES=	comms
MASTER_SITES=	http://www.freebsd.org/~fenner/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.freebsd.org/~fenner/

ONLY_FOR_PLATFORM=	SunOS-*-*        # untested on NetBSD

MAKE_ENV+=	CPPFLAGS="`${AWK} -F: '/^uucp:/ { printf(\"-DDAEMONUSER=%s -DDAEMONGROUP=%s\", $$3, $$4); }' /etc/passwd`"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qpage ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qpage.man ${PREFIX}/man/man1/qpage.1

.include "../../mk/bsd.pkg.mk"
