# $NetBSD: Makefile,v 1.6 2003/07/17 21:29:20 grant Exp $

DISTNAME=	exec-0.107
PKGNAME=	aap-0.107
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=a-a-p/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.a-a-p.org/
COMMENT=	make(1) replacement

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
