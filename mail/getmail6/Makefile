# $NetBSD: Makefile,v 1.2 2023/10/31 14:55:36 schmonz Exp $

DISTNAME=		getmail6-6.18.13
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=getmail6/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		https://getmail6.org/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none

REPLACE_PYTHON=		*.py getmail6core/*.py

SUBST_CLASSES+=		core
SUBST_STAGE.core=	pre-configure
SUBST_FILES.core=	* */*
SUBST_SED.core=		-e 's|getmailcore|getmail6core|g'

post-extract:
	cd ${WRKSRC} && \
	for f in getmail* docs/getmail*.1; do \
		g=$$(echo $$f | sed -e 's|getmail|getmail6|'); \
		${MV} $$f $$g; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
