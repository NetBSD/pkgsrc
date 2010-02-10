# $NetBSD: Makefile,v 1.12 2010/02/10 19:17:40 joerg Exp $
#

DISTNAME=		archivemail-0.7.2
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=archivemail/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://archivemail.sourceforge.net/
COMMENT=		Tool for archiving and compressing old email in mailboxes

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/archivemail

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} \
		CHANGELOG FAQ MANIFEST PKG-INFO README TODO \
		${DESTDIR}${PREFIX}/share/archivemail
	${INSTALL_MAN} ${WRKSRC}/archivemail.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
