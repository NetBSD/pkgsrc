# $NetBSD: Makefile,v 1.14 2012/03/15 11:53:29 obache Exp $
#

DISTNAME=		archivemail-0.9.0
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=archivemail/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://archivemail.sourceforge.net/
COMMENT=		Tool for archiving and compressing old email in mailboxes
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none

INSTALLATION_DIRS=	share/archivemail

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} \
		CHANGELOG FAQ MANIFEST PKG-INFO README TODO \
		${DESTDIR}${PREFIX}/share/archivemail

do-test:
	${RUN}cd ${WRKSRC};${SETENV} ${TEST_ENV} ${PYTHONBIN} test_archivemail

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
