# $NetBSD: Makefile,v 1.10 2025/02/03 21:13:48 bacon Exp $

DISTNAME=	man2html-${PKGVERSION}
PKGNAME=	man2html-20240105
CATEGORIES=	textproc
MASTER_SITES+=	https://invisible-island.net/archives/man2html/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invisible-island.net/scripts/man2html.html
COMMENT=	Convert nroff(1) man pages to HTML
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
NO_BUILD=	yes

REPLACE_PERL=	man2html

INSTALLATION_DIRS=	bin ${PREFIX}/${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/man2html ${DESTDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man2html.1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
