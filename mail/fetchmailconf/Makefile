# $NetBSD: Makefile,v 1.53 2003/09/13 21:20:15 tron Exp $

DISTNAME=	fetchmail-6.2.4
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/fetchmail/fetchmailconf/}
CATEGORIES=	mail
MASTER_SITES=	http://catb.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/fetchmail/
COMMENT=	Configuration tool for fetchmail

DEPENDS+=	${PKGNAME:S/conf//}:../../mail/fetchmail

NO_BUILD=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

DISTINFO_FILE=		${.CURDIR}/../../mail/fetchmail/distinfo
PATCHDIR=		${.CURDIR}/../../mail/fetchmail/patches

PYTHON_PATCH_SCRIPTS= fetchmailconf

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf ${PREFIX}/bin
		${LN} -s fetchmail.1 ${PREFIX}/man/man1/fetchmailconf.1

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
