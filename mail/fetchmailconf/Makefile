# $NetBSD: Makefile,v 1.68 2006/03/04 21:30:00 jlam Exp $

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

INSTALLATION_DIRS=	bin man/man1

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf ${PREFIX}/bin
		${LN} -s fetchmail.1 ${PREFIX}/man/man1/fetchmailconf.1

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
