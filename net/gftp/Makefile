# $NetBSD: Makefile,v 1.3 2001/05/15 07:56:43 rh Exp $

DISTNAME=	gftp-2.0.8
CATEGORIES=	net
MASTER_SITES=	http://gftp.seul.org/					\
		ftp://gftp.seul.org/pub/gftp/				\
		ftp://gftp.seul.org/pub/gftp/old-releases/

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://gftp.seul.org/
COMMENT=	multithreaded ftp client for *NIX based machines running X11R6

DEPENDS+=	gtk+>=1.2.3:../../x11/gtk

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include -D_POSIX_THREAD_SYSCALL_SOFT=1 ${CFLAGS}"

.include "../../mk/bsd.pkg.mk"
