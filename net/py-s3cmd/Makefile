# $NetBSD: Makefile,v 1.23 2022/01/22 14:34:18 wiz Exp $

DISTNAME=	s3cmd-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=s3tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://s3tools.org/s3cmd
COMMENT=	Command-line interface to Amazon's Simple Storage Service (S3)
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

MAKE_ENV+=		S3CMD_INSTPATH_MAN=${PKGMANDIR}

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.0.1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
