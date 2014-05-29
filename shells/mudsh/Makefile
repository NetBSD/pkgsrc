# $NetBSD: Makefile,v 1.17 2014/05/29 23:37:26 wiz Exp $
#

DISTNAME=	mudsh
PKGNAME=	mudsh-20010311
PKGREVISION=	3
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xirium.com/tech/mud-shell/index.html
COMMENT=	M.U.D. game-like shell

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin

do-build:
	@${CP} ${WRKSRC}/mudsh ${WRKSRC}/mudsh.orig
	@${SED} -e 's|/usr/local/bin/perl|${LOCALBASE}/bin/perl|g' \
		${WRKSRC}/mudsh.orig >${WRKSRC}/mudsh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mudsh ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
