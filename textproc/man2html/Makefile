# $NetBSD: Makefile,v 1.3 2019/08/11 13:23:25 wiz Exp $

DISTNAME=	man2html3.0.1
PKGNAME=	${DISTNAME:S/html/html-/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES+=	https://acadix.biz/Ports/distfiles/
MASTER_SITES+=	http://hydra.nac.uci.edu/indiv/ehood/tar/
MASTER_SITES+=	ftp://ftp.cpan.org/pub/CPAN/modules/by-authors/Earl_Hood/
MASTER_SITES+=	http://people.freebsd.org/~demon/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/man2html/
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
