# $NetBSD: Makefile,v 1.1 2026/05/03 13:18:24 kim Exp $

PKGNAME=	postfix-mta-sts-resolver-${VERSION}
CATEGORIES=	mail
MASTER_SITES=	# empty
DISTFILES=	# empty
DESCR_SRC=	../../mail/py-postfix-mta-sts-resolver/DESCR DESCR

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Snawoot/postfix-mta-sts-resolver
COMMENT=	Daemon providing TLS client policy for Postfix based on MTA-STS policy (meta package)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-postfix-mta-sts-resolver>=${VERSION}:../../mail/py-postfix-mta-sts-resolver

META_PACKAGE=	yes

.include "../../mail/py-postfix-mta-sts-resolver/version.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
