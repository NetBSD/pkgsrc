# $NetBSD: Makefile,v 1.34 2002/01/28 17:36:27 drochner Exp $

DISTNAME=	fetchmail-5.9.6
PKGNAME=	${DISTNAME:S/fetchmail/fetchmailconf/}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/ \
		http://www.tuxedo.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/fetchmail/
COMMENT=	Configuration tool for fetchmail

DEPENDS+=	${PKGNAME:S/conf//}:../../mail/fetchmail

NO_BUILD=	YES
USE_X11=	YES

EXTRACT_ELEMENTS= ${DISTNAME}/fetchmailconf

PYTHON_PATCH_SCRIPTS= fetchmailconf

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf ${PREFIX}/bin
		${LN} -s fetchmail.1 ${PREFIX}/man/man1/fetchmailconf.1

.include "../../lang/python/application.buildlink.mk"
.include "../../x11/py-Tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
