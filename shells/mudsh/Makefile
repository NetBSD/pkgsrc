# $NetBSD: Makefile,v 1.6 2004/04/18 04:27:20 snj Exp $
#

DISTNAME=	mudsh
PKGNAME=	mudsh-20010311
CATEGORIES=	shells
MASTER_SITES=	http://www.xirium.com/tech/mud-shell/download/
EXTRACT_SUFX=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xirium.com/tech/mud-shell/index.html
COMMENT=	M.U.D. game-like shell

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	YES
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

do-build:
	@${CP} ${WRKSRC}/mudsh ${WRKSRC}/mudsh.orig
	@${SED} -e 's|/usr/local/bin/perl|${LOCALBASE}/bin/perl|g' \
		${WRKSRC}/mudsh.orig >${WRKSRC}/mudsh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mudsh ${PREFIX}/bin

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
