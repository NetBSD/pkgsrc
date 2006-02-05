# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:53 joerg Exp $
#

DISTNAME=		archivemail-0.6.1
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=archivemail/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://archivemail.sourceforge.net/
COMMENT=		Tool for archiving and compressing old email in mailboxes

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	man/man1

do-build:

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py install \
		--prefix=${PREFIX}

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/archivemail
		cd ${WRKSRC} ; ${INSTALL_DATA} \
			CHANGELOG FAQ MANIFEST PKG-INFO README TODO \
			${PREFIX}/share/archivemail
		cd ${WRKSRC} ; ${INSTALL_MAN} \
			archivemail.1 \
			${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
