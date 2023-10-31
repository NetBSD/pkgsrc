# $NetBSD: Makefile,v 1.180 2023/10/31 14:56:12 schmonz Exp $

DISTNAME=		getmail-5.16
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}old-versions/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/getmail/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none

REPLACE_PYTHON=		*.py getmail5core/*.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 5.16

SUBST_CLASSES+=		core
SUBST_STAGE.core=	pre-configure
SUBST_FILES.core=	* */*
SUBST_SED.core=		-e 's|getmailcore|getmail5core|g'

post-extract:
	cd ${WRKSRC} && \
	for f in getmail* docs/getmail*.1; do \
		g=$$(echo $$f | sed -e 's|getmail|getmail5|'); \
		${MV} $$f $$g; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
