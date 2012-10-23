# $NetBSD: Makefile,v 1.11 2012/10/23 17:19:03 asau Exp $

DISTNAME=	s3cmd-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=s3tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://s3tools.org/s3cmd
COMMENT=	Command-line interface to Amazon's Simple Storage Service (S3)
LICENSE=	gnu-gpl-v2

PYDISTUTILSPKG=		yes
MAKE_ENV+=		S3CMD_INSTPATH_MAN=${PKGMANDIR}

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
