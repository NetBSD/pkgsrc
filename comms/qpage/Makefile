# $NetBSD: Makefile,v 1.3 2000/02/02 15:19:41 agc Exp $
#

DISTNAME=	qpage-3.3
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.qpage.org/

ONLY_FOR_PLATFORM=	SunOS-*-*        # untested on NetBSD

GNU_CONFIGURE=	yes

MAKE_ENV+=	CPPFLAGS="`${AWK} -F: '/^uucp:/ { 			\
	printf(\"-DDAEMONUSER=%s -DDAEMONGROUP=%s\", $$3, $$4); }'	\
	/etc/passwd`"

.include "../../mk/bsd.pkg.mk"
