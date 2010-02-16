# $NetBSD: Makefile,v 1.6 2010/02/16 14:37:11 wiz Exp $
#

DISTNAME=	t-prot-2.15
CATEGORIES=	mail
MASTER_SITES=	http://www.escape.de/users/tolot/mutt/t-prot/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.escape.de/users/tolot/mutt/t-prot/
COMMENT=	TOFU enhancement to mutt for condensing quoted text

DEPENDS+=	p5-Getopt-Mixed>=1.10:../../devel/p5-Getopt-Mixed

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=	t-prot

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/t-prot

do-configure do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/t-prot ${DESTDIR}${PREFIX}/bin/t-prot
	${INSTALL_MAN} ${WRKSRC}/t-prot.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/t-prot.1
	${INSTALL_DATA} ${WRKSRC}/contrib/muttrc.t-prot \
		${DESTDIR}${PREFIX}/share/doc/t-prot/

.include "../../mk/bsd.pkg.mk"
