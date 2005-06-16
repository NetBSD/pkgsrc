# $NetBSD: Makefile,v 1.64 2005/06/16 06:58:02 jlam Exp $

DISTNAME=	fetchmail-6.2.5
PKGNAME=	${DISTNAME:S/fetchmail/fetchmailconf/}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.catb.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/fetchmail/
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
