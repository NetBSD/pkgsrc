# $NetBSD: Makefile,v 1.1.1.1 2001/01/21 18:18:04 fredb Exp $
#

DISTNAME=	${PKGNAME:S,manedit-,manedit,}
PKGNAME=	manedit-0.4e
CATEGORIES=	editors
MASTER_SITES=	ftp://fox.mit.edu/pub/xsw/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://wolfpack.twu.net/ManEdit/

DEPENDS+=	gtk+-*:../../x11/gtk

WRKSRC=		${WRKDIR}/${DISTNAME}/manedit

post-patch:
		${SED}	-e "s,@PREFIX@,${PREFIX},g" -e "s,@CC@,${CC},g" \
			-e "s,@CFLAGS@,${CFLAGS},g" < ${WRKSRC}/Makefile \
			> ${WRKSRC}/Makefile.done
		${MV} ${WRKSRC}/Makefile.done ${WRKSRC}/Makefile
		${SED}	-e "s,@PREFIX@,${PREFIX},g" < ${WRKSRC}/manedit.1 \
			> ${WRKSRC}/manedit.1.done
		${MV} ${WRKSRC}/manedit.1.done ${WRKSRC}/manedit.1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/manedit ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/share/manedit \
			${PREFIX}/share/manedit/templates \
			${PREFIX}/share/manedit/icons
		${INSTALL_MAN} ${WRKSRC}/manedit.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/help/manpage_writing_procedures \
			${PREFIX}/man/man7/manpage_writing_procedures.7
		${INSTALL_MAN} ${WRKSRC}/help/manpage_xml_referance \
			${PREFIX}/man/man7/manpage_xml_reference.7
		cd ${WRKSRC}/templates && ${INSTALL_DATA} api.mpt config.mpt \
			intro.mpt program.mpt ${PREFIX}/share/manedit/templates
		cd ${WRKSRC} && ${INSTALL_DATA} manedit.xpm \
			${PREFIX}/share/manedit/icons

.include "../../mk/bsd.pkg.mk"
