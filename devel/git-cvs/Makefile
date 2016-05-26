# $NetBSD: Makefile,v 1.1 2016/05/26 15:36:59 khorben Exp $

.include "../../devel/git/Makefile.version"

DISTNAME=	# empty
PKGNAME=	git-cvs-${GIT_VERSION}
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Salvages data out of another SCM people love to hate.
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
DEPENDS+=	cvsps:../../devel/cvsps

.include "../../mk/bsd.pkg.mk"
