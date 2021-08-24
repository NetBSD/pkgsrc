# $NetBSD: Makefile,v 1.1 2021/08/24 10:13:49 mef Exp $

R_PKGNAME=	gitcreds
R_PKGVER=	0.1.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Query 'git' Credentials from 'R'
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-oskeyring-[0-9]*:../../security/R-oskeyring
USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
