# $NetBSD: Makefile,v 1.28 2001/09/27 23:18:21 jlam Exp $

DISTNAME=	fetchmail-5.9.0
PKGNAME=	${DISTNAME:S/fetchmail/fetchmailconf/}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/ \
		http://www.tuxedo.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/fetchmail/
COMMENT=	Configuration tool for fetchmail

DEPENDS+=	${DISTNAME}:../../mail/fetchmail
DEPENDS+=	py-Tk-[0-9]*:../../x11/py-Tk

DISTINFO_FILE=	${.CURDIR}/../fetchmail/distinfo
NO_BUILD=	YES
USE_X11=	YES

EXTRACT_ELEMENTS= ${DISTNAME}/fetchmailconf

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf ${PREFIX}/bin
		${LN} -s fetchmail.1 ${PREFIX}/man/man1/fetchmailconf.1

.include "../../mk/bsd.pkg.mk"
