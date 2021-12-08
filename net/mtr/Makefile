# $NetBSD: Makefile,v 1.116 2021/12/08 16:06:03 adam Exp $

DISTNAME=	mtr-0.94
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	share/doc/mtr

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__=1

.include "options.mk"

SPECIAL_PERMS=	sbin/mtr-packet ${SETUID_ROOT_PERMS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/mtr

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
