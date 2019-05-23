# $NetBSD: Makefile,v 1.30 2019/05/23 19:23:13 rillig Exp $
#

DISTNAME=	papersize-1.0.8
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manipulate the default papersize in certain packages

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	getpapersize setpapersize
SUBST_VARS.paths=	SH
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	X11BASE
SUBST_VARS.paths+=	ECHO
SUBST_VARS.paths+=	AWK
SUBST_VARS.paths+=	LOCALBASE
SUBST_VARS.paths+=	SED
SUBST_VARS.paths+=	GREP
SUBST_VARS.paths+=	MV
SUBST_VARS.paths+=	TR
SUBST_VARS.paths+=	RM
SUBST_VARS.paths+=	CHMOD

do-extract:
	cd ${FILESDIR} && cp setpapersize getpapersize ${WRKSRC}/.

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/setpapersize ${DESTDIR}${PREFIX}/bin/setpapersize
	${INSTALL_SCRIPT} ${WRKSRC}/getpapersize ${DESTDIR}${PREFIX}/bin/getpapersize
	${INSTALL_MAN} ${FILESDIR}/getpapersize.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/getpapersize.1
	${INSTALL_MAN} ${FILESDIR}/setpapersize.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/setpapersize.1

.include "../../mk/bsd.pkg.mk"
