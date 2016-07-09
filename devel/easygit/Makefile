# $NetBSD: Makefile,v 1.10 2016/07/09 06:38:06 wiz Exp $

DISTNAME=		easygit-1.7.5.2
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://people.gnome.org/~newren/eg/download/${PKGVERSION}/
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
