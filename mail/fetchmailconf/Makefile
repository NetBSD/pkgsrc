# $NetBSD: Makefile,v 1.13 2000/11/27 15:59:07 frueauf Exp $

DISTNAME=	fetchmail-5.6.0
PKGNAME=	${DISTNAME:S/fetchmail/fetchmailconf/}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/ \
		http://www.tuxedo.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/fetchmail/

DEPENDS+=	${DISTNAME}:../../mail/fetchmail
DEPENDS+=	py-Tk-*:../../x11/py-Tk

FILESDIR=	${.CURDIR}/../fetchmail/files
NO_BUILD=	YES
USE_X11=	YES

EXTRACT_ELEMENTS= ${DISTNAME}/fetchmailconf

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf ${PREFIX}/bin/
		${LN} -s fetchmail.1 ${PREFIX}/man/man1/fetchmailconf.1

.include "../../mk/bsd.pkg.mk"
