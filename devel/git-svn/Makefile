# $NetBSD: Makefile,v 1.6 2024/06/28 14:06:03 ryoon Exp $

.include "../../devel/git/Makefile.version"

DISTNAME=	# empty
PKGNAME=	git-svn-${GIT_VERSION}
PKGREVISION=	1
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bidirectional operation between a Subversion repository and git
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

DEPENDS+=	git-perlscripts>=${GIT_VERSION}:../../devel/git-perlscripts
DEPENDS+=	p5-subversion-[0-9]*:../../devel/p5-subversion

.include "../../mk/bsd.pkg.mk"
