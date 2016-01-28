# $NetBSD: Makefile,v 1.6 2016/01/28 13:38:53 jperkin Exp $

DISTNAME=	bsdinstall-20160108
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Portable version of the BSD install(1) program
LICENSE=	modified-bsd

BOOTSTRAP_PKG=	yes

USE_BSD_MAKEFILE=	yes
USE_FEATURES=		nbcompat

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}
	@${TOUCH} ${WRKSRC}/bsdinstall.cat1

CPPFLAGS+=	-D_PATH_DEVNULL=\"/dev/null\"
CPPFLAGS+=	-DTARGET_STRIP=\"${TOOLS_PLATFORM.strip:Q}\"

CPPFLAGS.SunOS+=	-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MSunOS-5.11-*)
MAKE_ENV+=	NOGCCERROR=yes
.endif

.include "../../mk/bsd.pkg.mk"
