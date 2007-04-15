# $NetBSD: Makefile,v 1.1.1.1 2007/04/15 21:18:46 agc Exp $
#

DISTNAME=	t-prot-2.4
CATEGORIES=	mail
MASTER_SITES=	http://www.escape.de/users/tolot/mutt/t-prot/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.escape.de/users/tolot/mutt/t-prot/
COMMENT=	TOFU enhancement to mutt for condensing quoted text

DEPENDS+=	p5-Getopt-Mixed>=1.10:../../devel/p5-Getopt-Mixed

REPLACE_PERL+=	t-prot

do-configure do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/t-prot ${PREFIX}/bin/t-prot
	${INSTALL_MAN} ${WRKSRC}/t-prot.1 ${PREFIX}/${PKGMANDIR}/man1/t-prot.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/t-prot
	${INSTALL_DATA} ${WRKSRC}/contrib/muttrc.t-prot ${PREFIX}/share/doc/t-prot/

.include "../../mk/bsd.pkg.mk"
