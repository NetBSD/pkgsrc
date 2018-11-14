# $NetBSD: Makefile,v 1.106 2018/11/14 22:22:12 kleink Exp $

DISTNAME=	mtr-0.92
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	share/doc/mtr

.include "options.mk"

SPECIAL_PERMS=	sbin/mtr-packet ${SETUID_ROOT_PERMS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/mtr

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
