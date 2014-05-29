# $NetBSD: Makefile,v 1.7 2014/05/29 23:35:35 wiz Exp $

DISTNAME=		easygit-1.6.5.3
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		http://people.gnome.org/~newren/eg/download/1.6.5.3/
DIST_SUBDIR=		${PKGNAME_NOREV}
DISTFILES=		eg

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://people.gnome.org/~newren/eg/
COMMENT=		Git porcelain wrapper in Perl

LICENSE=		gnu-gpl-v2

DEPENDS+=		git>=1.6.1:../../devel/git
WRKSRC=			${WRKDIR}
NO_BUILD=		yes
USE_TOOLS+=		perl
REPLACE_PERL=		eg
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/eg ${DESTDIR}${PREFIX}/bin/eg
	${LN} -s ${DESTDIR}${PREFIX}/bin/eg ${DESTDIR}${PREFIX}/bin/easygit

.include "../../mk/bsd.pkg.mk"
