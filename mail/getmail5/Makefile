# $NetBSD: Makefile,v 1.1 2025/10/19 19:46:48 jym Exp $

DISTNAME=		getmail-5.16
PKGNAME=		getmail5-5.16
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}old-versions/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://pyropus.ca/software/getmail/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2 AND apache-2.0

USE_LANGUAGES=		# none

REPLACE_PYTHON=		*.py getmail5core/*.py
PYTHON_VERSIONS_ACCEPTED=	27 # getmail5 only supports Python 2

CONFLICTS+=		getmail6-[0-9]*

# Package-wide renaming of getmail to getmail5
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
