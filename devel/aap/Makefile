# $NetBSD: Makefile,v 1.2 2002/11/23 22:34:22 cjep Exp $

DISTNAME=	exec-0.107
PKGNAME=	aap-0.107
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=a-a-p/}
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.a-a-p.org/
COMMENT=

WRKSRC=		${WRKDIR}

AAP_DIR=	${PREFIX}/lib/aap
AAP_DOC=	${PREFIX}/share/doc/aap
AAP_START=	${PREFIX}/bin/aap
AAP=		./aap PREFIX=${PREFIX}

PYTHON_PATCH_SCRIPTS=	Filetype.py Main.py PkgInstall.py PrintProfile.py \
			__init__.py aap
PYTHON_VERSIONS_ACCEPTED=	21

do-build:
	@cd ${WRKSRC} && ${AAP}

do-install:
	@cd ${WRKSRC} && ${AAP} install

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
