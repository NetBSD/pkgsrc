# $NetBSD: Makefile,v 1.13 2003/05/02 11:54:46 wiz Exp $
#

DISTNAME=	manedit-0.5.6
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/manedit
CATEGORIES=	editors
MASTER_SITES=	ftp://wolfpack.twu.net/users/wolfpack/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wolfpack.twu.net/ManEdit/
COMMENT=	UNIX Manual (man, manpage) page editor, viewer, and browser for X11

USE_BUILDLINK2=	YES

MAKE_ENV+=	CPP="${CXX}"

# The FreeBSD makefile may be used as "generic UNIX".
MAKEFILE=	Makefile.FreeBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/manedit ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/manview.sh ${PREFIX}/bin/manview
	${INSTALL_SCRIPT} ${WRKSRC}/utils/manwrap.sh ${PREFIX}/bin/manwrap
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

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
