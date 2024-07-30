# $NetBSD: Makefile,v 1.7 2024/07/30 11:48:45 adam Exp $

.include "../../devel/git/Makefile.version"

DISTNAME=	# empty
PKGNAME=	git-svn-${GIT_VERSION}
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bidirectional operation between a Subversion repository and git
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

DEPENDS+=	git-perlscripts>=${GIT_VERSION}:../../devel/git-perlscripts
DEPENDS+=	p5-subversion-[0-9]*:../../devel/p5-subversion

.include "../../mk/bsd.pkg.mk"
