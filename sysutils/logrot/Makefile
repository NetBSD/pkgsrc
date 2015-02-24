# $NetBSD: Makefile,v 1.11 2015/02/24 08:58:57 wiz Exp $

DISTNAME=	logrot-1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mewburn.net/luke/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mewburn.net/luke/software.html
COMMENT=	Rotate log files in a safe and configurable manner

GNU_CONFIGURE=	YES

OPSYSVARS+=		CONFIGURE_ARGS
CONFIGURE_ARGS.NetBSD+=	--with-pidfile=/var/run/syslogd.pid

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
