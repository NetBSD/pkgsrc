# $NetBSD: Makefile,v 1.9 2001/08/17 21:16:50 jlam Exp $
#

DISTNAME=	${PKGNAME:S,manedit-,manedit,}
PKGNAME=	manedit-0.4j
CATEGORIES=	editors
MASTER_SITES=	ftp://wolfpack.twu.net/users/wolfpack/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wolfpack.twu.net/ManEdit/
COMMENT=	UNIX Manual (man, manpage) page editor, viewer, and browser for X11

WRKSRC=		${WRKDIR}/${DISTNAME}/manedit

USE_BUILDLINK_ONLY=	YES

MAKE_ENV+=	CPP="${CXX}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/manedit ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/manedit			\
		${PREFIX}/share/manedit/templates			\
		${PREFIX}/share/manedit/icons
	${INSTALL_MAN} ${WRKSRC}/manedit.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/help/manpage_writing_procedures	\
		${PREFIX}/man/man7/manpage_writing_procedures.7
	${INSTALL_MAN} ${WRKSRC}/help/manpage_xml_referance		\
		${PREFIX}/man/man7/manpage_xml_reference.7
	cd ${WRKSRC}/templates && ${INSTALL_DATA} api.mpt config.mpt	\
		intro.mpt program.mpt ${PREFIX}/share/manedit/templates
	cd ${WRKSRC} && ${INSTALL_DATA} manedit.xpm			\
		${PREFIX}/share/manedit/icons

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
