# $NetBSD: Makefile,v 1.12 2003/07/21 17:10:38 martti Exp $

DISTNAME=	gftp-2.0.8
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://gftp.seul.org/					\
		ftp://gftp.seul.org/pub/gftp/				\
		ftp://gftp.seul.org/pub/gftp/old-releases/

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://gftp.seul.org/
COMMENT=	Multithreaded ftp client for *NIX based machines running X11R6

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include -D_POSIX_THREAD_SYSCALL_SOFT=1 ${CFLAGS}"

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
