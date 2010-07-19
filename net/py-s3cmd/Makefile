# $NetBSD: Makefile,v 1.1 2010/07/19 16:42:12 ver Exp $

DISTNAME=	s3cmd-0.9.9.91
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=s3tools/files/s3cmd/}

MAINTAINER=	ver@NetBSD.org
HOMEPAGE=	http://s3tools.org/s3cmd
COMMENT=	Command-line interface to Amazon's Simple Storage Service (S3)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG= 	yes
MAKE_ENV+=		S3CMD_INSTPATH_MAN=man

DEPENDS+=	${PYPKGPREFIX}-expat:../../textproc/py-expat

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
