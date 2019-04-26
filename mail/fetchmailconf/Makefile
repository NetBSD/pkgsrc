# $NetBSD: Makefile,v 1.99 2019/04/26 13:14:03 maya Exp $

DISTNAME=	fetchmail-6.3.26
PKGNAME=	${DISTNAME:S/fetchmail/fetchmailconf/}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fetchmail/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fetchmail.info/
COMMENT=	Configuration tool for fetchmail

DEPENDS+=	${DISTNAME}{,nb*}:../../mail/fetchmail
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

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
REPLACE_PYTHON=	fetchmailconf.py
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 6.3.22

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf.py ${DESTDIR}${PREFIX}/bin/fetchmailconf
	${LN} -s fetchmail.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/fetchmailconf.1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
