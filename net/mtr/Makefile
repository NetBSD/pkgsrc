# $NetBSD: Makefile,v 1.109 2019/09/07 18:50:19 kim Exp $

DISTNAME=	mtr-0.93
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/

PATCH_SITES=		https://github.com/traviscross/mtr/commit/
PATCH_DIST_STRIP=	-p1
# For improved errors
PATCHFILES=		919422d1dee7d35a236035f190f491a4a2113772.patch
# Fix find_source_addr
PATCHFILES+=		9fe183d61f5382bd6dae1df1db6439a27e8edde2.patch

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
