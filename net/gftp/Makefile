# $NetBSD: Makefile,v 1.5 2002/10/21 15:07:22 wiz Exp $

DISTNAME=	gftp-2.0.8
CATEGORIES=	net
MASTER_SITES=	http://gftp.seul.org/					\
		ftp://gftp.seul.org/pub/gftp/				\
		ftp://gftp.seul.org/pub/gftp/old-releases/

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://gftp.seul.org/
COMMENT=	multithreaded ftp client for *NIX based machines running X11R6

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include -D_POSIX_THREAD_SYSCALL_SOFT=1 ${CFLAGS}"

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
