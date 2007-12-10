# $NetBSD: Makefile,v 1.29 2007/12/10 01:14:41 obache Exp $
#

DISTNAME=	manedit-0.8.1
CATEGORIES=	editors
MASTER_SITES=	ftp://wolfpack.twu.net/users/wolfpack/	\
		ftp://gd.tuwien.ac.at/games/wolfpack/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wolfpack.twu.net/ManEdit/
COMMENT=	UNIX Manual (man, manpage) page editor, viewer, and browser for X11

WRKSRC=		${WRKDIR}/${DISTNAME}/manedit

USE_LANGUAGES=	c c++

MAKE_ENV+=	CPP=${CXX:Q}

# The FreeBSD makefile may be used as "generic UNIX".
MAKE_FILE=	Makefile.FreeBSD

INSTALLATION_DIRS_FROM_PLIST=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/manedit ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/manview.sh ${PREFIX}/bin/manview
	${INSTALL_SCRIPT} ${WRKSRC}/utils/manwrap.sh ${PREFIX}/bin/manwrap
	${INSTALL_MAN} ${WRKSRC}/manedit.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/help/manpage_writing_procedures	\
		${PREFIX}/${PKGMANDIR}/man7/manpage_writing_procedures.7
	${INSTALL_MAN} ${WRKSRC}/help/manpage_xml_reference		\
		${PREFIX}/${PKGMANDIR}/man7/manpage_xml_reference.7
	cd ${WRKSRC}/templates && ${INSTALL_DATA} *.mpt			\
		${PREFIX}/share/manedit/templates
	cd ${WRKSRC} && ${INSTALL_DATA} manedit.xpm			\
		${PREFIX}/share/manedit/icons

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
