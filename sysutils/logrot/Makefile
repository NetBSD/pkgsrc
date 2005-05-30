# $NetBSD: Makefile,v 1.8 2005/05/30 04:05:46 lukem Exp $
#

DISTNAME=	logrot-1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mewburn.net/luke/src/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.mewburn.net/luke/software.html
COMMENT=	Rotate log files in a safe and configurable manner

GNU_CONFIGURE=	YES

OPSYSVARS+=		CONFIGURE_ARGS
CONFIGURE_ARGS.NetBSD+=	--with-pidfile=/var/run/syslogd.pid

.include "../../mk/bsd.pkg.mk"
