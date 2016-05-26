# $NetBSD: Makefile,v 1.2 2016/05/26 16:22:22 wiz Exp $

.include "../../devel/git/Makefile.version"

DISTNAME=	# empty
PKGNAME=	git-cvs-${GIT_VERSION}
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Backend for git to extract data from CVS
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
DEPENDS+=	cvsps-[0-9]*:../../devel/cvsps

.include "../../mk/bsd.pkg.mk"
