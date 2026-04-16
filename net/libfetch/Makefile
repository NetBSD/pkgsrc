# $NetBSD: Makefile,v 1.69 2026/04/16 09:58:56 wiz Exp $

DISTNAME=	libfetch-2.40
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.FreeBSD.org/
COMMENT=	Library to access HTTP/FTP server
LICENSE=	modified-bsd

USE_FEATURES=		nbcompat

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS+=	include
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	lib/pkgconfig
INSTALLATION_DIRS+=	${PKGMANDIR}/cat3
INSTALLATION_DIRS+=	${PKGMANDIR}/man3

BUILD_TARGET=	depend all
INSTALL_TARGET=	install includes
MAKE_ENV+=	SED=${SED:Q}

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}
	${TOUCH} ${WRKSRC}/fetch.cat3

SUBST_CLASSES+=	pc
SUBST_STAGE.pc=	post-extract
SUBST_FILES.pc=	fetch.pc.in
SUBST_VARS.pc=	COMMENT HOMEPAGE PKGBASE PKGVERSION_NOREV

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
