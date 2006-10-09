# $NetBSD: Makefile,v 1.8 2006/10/09 12:46:26 joerg Exp $
#

DISTNAME=		archivemail-0.6.1
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=archivemail/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://archivemail.sourceforge.net/
COMMENT=		Tool for archiving and compressing old email in mailboxes

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	man/man1 share/archivemail

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} \
		CHANGELOG FAQ MANIFEST PKG-INFO README TODO \
		${DESTDIR}${PREFIX}/share/archivemail
	${INSTALL_MAN} ${WRKSRC}/archivemail.1 ${DESTDIR}${PREFIX}/man/man1

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
