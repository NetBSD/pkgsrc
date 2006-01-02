# $NetBSD: Makefile,v 1.23 2006/01/02 23:15:49 joerg Exp $
#

DISTNAME=	papersize-1.0.8
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Manipulate the default papersize in certain packages

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-build
SUBST_FILES.paths=	getpapersize setpapersize

SUBST_SED.paths=	-e 's,@SH@,${SH},'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'
SUBST_SED.paths+=	-e 's,@X11BASE@,${X11BASE},'
SUBST_SED.paths+=	-e 's,@ECHO@,${ECHO},'
SUBST_SED.paths+=	-e 's,@AWK@,${AWK},'
SUBST_SED.paths+=	-e 's,@LOCALBASE@,${LOCALBASE},'
SUBST_SED.paths+=	-e 's,@SED@,${SED},'
SUBST_SED.paths+=	-e 's,@GREP@,${GREP},'
SUBST_SED.paths+=	-e 's,@MV@,${MV},'
SUBST_SED.paths+=	-e 's,@TR@,${TR},'
SUBST_SED.paths+=	-e 's,@RM@,${RM},'
SUBST_SED.paths+=	-e 's,@CHMOD@,${CHMOD},'

do-build:
	@for f in setpapersize getpapersize; do			\
		${CP} ${FILESDIR}/$$f ${WRKSRC}/$$f;		\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/setpapersize ${PREFIX}/bin/setpapersize
	${INSTALL_SCRIPT} ${WRKSRC}/getpapersize ${PREFIX}/bin/getpapersize
	${INSTALL_MAN} ${FILESDIR}/getpapersize.1 ${PREFIX}/${PKGMANDIR}/man1/getpapersize.1
	${INSTALL_MAN} ${FILESDIR}/setpapersize.1 ${PREFIX}/${PKGMANDIR}/man1/setpapersize.1

.include "../../mk/bsd.pkg.mk"
