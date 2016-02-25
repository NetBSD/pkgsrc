# $NetBSD: Makefile,v 1.12 2016/02/25 08:27:04 jperkin Exp $

DISTNAME=	logrot-1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mewburn.net/luke/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mewburn.net/luke/software.html
COMMENT=	Rotate log files in a safe and configurable manner

GNU_CONFIGURE=	YES

CONFIGURE_ARGS.NetBSD+=	--with-pidfile=/var/run/syslogd.pid

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
