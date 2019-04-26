# $NetBSD: Makefile,v 1.24 2019/04/26 14:12:41 maya Exp $

DISTNAME=		archivemail-0.9.0
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=archivemail/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://archivemail.sourceforge.net/
COMMENT=		Tool for archiving and compressing old email in mailboxes
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none

INSTALLATION_DIRS=	share/archivemail

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.9.0

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} \
		CHANGELOG FAQ MANIFEST PKG-INFO README TODO \
		${DESTDIR}${PREFIX}/share/archivemail

do-test:
	${RUN}cd ${WRKSRC};${SETENV} ${TEST_ENV} ${PYTHONBIN} test_archivemail

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
