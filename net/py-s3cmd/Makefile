# $NetBSD: Makefile,v 1.5 2010/10/09 09:34:07 obache Exp $

DISTNAME=	s3cmd-0.9.9.91
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=s3tools/}

MAINTAINER=	ver@NetBSD.org
HOMEPAGE=	http://s3tools.org/s3cmd
COMMENT=	Command-line interface to Amazon's Simple Storage Service (S3)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=		yes
MAKE_ENV+=		S3CMD_INSTPATH_MAN=${PKGMANDIR}

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
.if ${PYPKGPREFIX} == "py24"
DEPENDS+=	${PYPKGPREFIX}-elementtree-[0-9]*:../../textproc/py-elementtree
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
