# $NetBSD: Makefile,v 1.40.4.1 2002/10/14 10:42:50 agc Exp $

DISTNAME=	fetchmail-6.1.0
PKGNAME=	${DISTNAME:S/fetchmail/fetchmailconf/}
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

DISTINFO_FILE=		${.CURDIR}/../../mail/fetchmail/distinfo
PATCHDIR=		${.CURDIR}/../../mail/fetchmail/patches

PYTHON_PATCH_SCRIPTS= fetchmailconf

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf ${PREFIX}/bin
		${LN} -s fetchmail.1 ${PREFIX}/man/man1/fetchmailconf.1

.include "../../lang/python/application.buildlink.mk"
.include "../../x11/py-Tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
