# $NetBSD: Makefile,v 1.9 2022/06/28 11:36:12 wiz Exp $

DISTNAME=	man2html3.0.1
PKGNAME=	${DISTNAME:S/html/html-/}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES+=	https://acadix.biz/Ports/distfiles/
MASTER_SITES+=	http://hydra.nac.uci.edu/indiv/ehood/tar/
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=../../authors/Earl_Hood/}
MASTER_SITES+=	http://people.freebsd.org/~demon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/man2html/
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
