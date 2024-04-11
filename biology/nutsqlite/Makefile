# $NetBSD $

DISTNAME=	NUTsqlite-2.0.6
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nut/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nut.sourceforge.net/
COMMENT=	Record what you eat and analyze your meals
LICENSE=	gnu-gpl-v2

DEPENDS+=	tcl-[0-9]*:../../lang/tcl
DEPENDS+=	tk-[0-9]*:../../x11/tk
DEPENDS+=	sqlite3-[0-9]*:../../databases/sqlite3

WRKSRC=		${WRKDIR}/nutsqlite-2.0.6
EXTRACT_DIR=	${WRKSRC}

SUPERSEDES+=	nut-[0-9]*

INSTALLATION_DIRS=	bin libexec/nut ${PKGMANDIR}/man1 share/doc/nut

SUBST_CLASSES+=		scripts
SUBST_STAGE.scripts=	pre-build
SUBST_FILES.scripts=	nut nut-update
SUBST_VARS.scripts=	PREFIX

FILESDIR=	${PKGDIR}/files

post-extract:
	${CP} ${FILESDIR}/nut ${FILESDIR}/nut-update \
		${FILESDIR}/README.pkgsrc.txt ${WRKSRC}

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nut ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/nut-update ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/nut.tcl ${DESTDIR}${PREFIX}/libexec/nut
	${INSTALL_DATA} ${WRKSRC}/updateNUT.tcl ${DESTDIR}${PREFIX}/libexec/nut
	${INSTALL_MAN} ${WRKSRC}/nut.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nut
	${INSTALL_MAN} ${WRKSRC}/README.pkgsrc.txt ${DESTDIR}${PREFIX}/share/doc/nut


.include "../../mk/bsd.pkg.mk"
