# $NetBSD: Makefile,v 1.3 2014/08/25 07:51:48 adam Exp $

.include "../../devel/git/Makefile.version"

DISTNAME=	# empty
PKGNAME=	git-svn-${GIT_VERSION}
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bidirectional operation between a Subversion repository and git
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
DEPENDS+=	p5-subversion-[0-9]*:../../devel/p5-subversion

.include "../../mk/bsd.pkg.mk"
