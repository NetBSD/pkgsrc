# $NetBSD: Makefile,v 1.1.1.1 2004/06/30 19:12:13 hubertf Exp $
#

DISTNAME=		archivemail-0.6.1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=archivemail/}

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://archivemail.sourceforge.net/
COMMENT=		Tool for archiving and compressing old email in mailboxes

NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_BUILDLINK3=		yes

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
