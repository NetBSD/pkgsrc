# $NetBSD: Makefile,v 1.3 2003/06/02 01:17:00 jschauma Exp $
#

DISTNAME=	mudsh
PKGNAME=	mudsh-20010311
WRKSRC=		${WRKDIR}
CATEGORIES=	shells
MASTER_SITES=	http://www.xirium.com/tech/mud-shell/download/
EXTRACT_SUFX=	# empty

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.xirium.com/tech/mud-shell/index.html
COMMENT=	M.U.D. game-like shell

USE_BUILDLINK2=YES
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

do-build:
	@${CP} ${WRKSRC}/mudsh ${WRKSRC}/mudsh.orig
	@${SED} -e 's|/usr/local/bin/perl|${LOCALBASE}/bin/perl|g' \
		${WRKSRC}/mudsh.orig >${WRKSRC}/mudsh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mudsh ${PREFIX}/bin

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
