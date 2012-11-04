# $NetBSD: Makefile,v 1.83.2.1 2012/11/04 17:12:30 spz Exp $

DISTNAME=	fetchmail-6.3.22
PKGNAME=	${DISTNAME:S/fetchmail/fetchmailconf/}
CATEGORIES=	mail
MASTER_SITES=	http://download.berlios.de/fetchmail/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fetchmail.berlios.de/
COMMENT=	Configuration tool for fetchmail

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${DISTNAME}{,nb*}:../../mail/fetchmail

NO_BUILD=	YES

DISTINFO_FILE=		${.CURDIR}/../../mail/fetchmail/distinfo
PATCHDIR=		${.CURDIR}/../../mail/fetchmail/patches

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-hesiod
LDFLAGS+=		${CFLAGS}
USE_TOOLS+=		msgfmt tbl
USE_LANGUAGES+=		c

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALL_TARGET=		install-pythonPYTHON

PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
PYTHON_PATCH_SCRIPTS=	fetchmailconf.py

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf.py ${DESTDIR}${PREFIX}/bin/fetchmailconf
	${LN} -s fetchmail.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/fetchmailconf.1

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
