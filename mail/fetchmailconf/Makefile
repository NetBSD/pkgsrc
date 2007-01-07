# $NetBSD: Makefile,v 1.69 2007/01/07 09:13:58 rillig Exp $

DISTNAME=	fetchmail-6.2.5.5
PKGNAME=	${DISTNAME:S/fetchmail/fetchmailconf/}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://download.berlios.de/fetchmail/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fetchmail.berlios.de/
COMMENT=	Configuration tool for fetchmail

DEPENDS+=	${DISTNAME}{,nb*}:../../mail/fetchmail

NO_BUILD=	YES

DISTINFO_FILE=		${.CURDIR}/../../mail/fetchmail/distinfo
PATCHDIR=		${.CURDIR}/../../mail/fetchmail/patches

PYTHON_PATCH_SCRIPTS= fetchmailconf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf ${PREFIX}/bin
		${LN} -s fetchmail.1 ${PREFIX}/${PKGMANDIR}/man1/fetchmailconf.1

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
