# $NetBSD: Makefile,v 1.19 2022/06/28 11:35:26 wiz Exp $
#

PKGNAME=	texlive2pkg-1.11
PKGREVISION=	1
CATEGORIES=	pkgtools

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Tool to automate initial steps in building a texlive package
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		yes
NO_BUILD=		yes
USE_LANGUAGES=		# none
USE_TOOLS+=		ftp:run perl:run xzcat:run
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	pre-configure
SUBST_MESSAGE.tools=	Substituting tool locations.
SUBST_FILES.tools=	texlive2pkg.sh
SUBST_VARS.tools=	DISTDIR MAKE PREFIX
SUBST_SED.tools=	-e 's,@FTP@,${TOOLS_PATH.ftp},g'

REPLACE_PERL+=		texlive.pkg texlive.pkg.doc

INSTALLATION_DIRS+=	bin libexec/texlive2pkg ${PKGMANDIR}/man8

do-extract:
	${CP} ${FILESDIR}/texlive2pkg.sh ${WRKSRC}
	${CP} ${FILESDIR}/texlive2pkg.8 ${WRKSRC}
	${CP} ${FILESDIR}/texlive.pkg* ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/texlive2pkg.sh ${DESTDIR}${PREFIX}/bin/texlive2pkg
	${INSTALL_SCRIPT} ${WRKSRC}/texlive.pkg ${DESTDIR}${PREFIX}/libexec/texlive2pkg/texlive.pkg
	${INSTALL_SCRIPT} ${WRKSRC}/texlive.pkg.doc ${DESTDIR}${PREFIX}/libexec/texlive2pkg/texlive.pkg.doc
	${INSTALL_MAN} ${WRKSRC}/texlive2pkg.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/texlive2pkg.8

.include "../../mk/bsd.pkg.mk"
