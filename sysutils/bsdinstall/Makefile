# $NetBSD: Makefile,v 1.1 2013/08/28 11:42:36 jperkin Exp $

DISTNAME=	bsdinstall-20130828
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Portable version of the BSD install(1) program

BOOTSTRAP_PKG=	yes

USE_BSD_MAKEFILE=	yes
USE_FEATURES=		nbcompat

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

CPPFLAGS+=	-D_PATH_DEVNULL=\"/dev/null\"
CPPFLAGS+=	-DTARGET_STRIP=\"${TOOLS_PLATFORM.strip:Q}\"

.include "../../mk/bsd.pkg.mk"
