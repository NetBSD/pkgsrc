# $NetBSD: Makefile,v 1.9 2012/10/03 23:40:37 cheusov Exp $

DISTNAME=	s3cmd-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=s3tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://s3tools.org/s3cmd
COMMENT=	Command-line interface to Amazon's Simple Storage Service (S3)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=		yes
MAKE_ENV+=		S3CMD_INSTPATH_MAN=${PKGMANDIR}

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
