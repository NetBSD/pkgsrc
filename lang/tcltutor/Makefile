# $NetBSD: Makefile,v 1.1 2019/10/07 14:37:34 kamil Exp $

DISTNAME=	tcltutor30b7
PKGNAME=	${DISTNAME:S/tcltutor/tcltutor-/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_OPENBSD:=distfiles/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	http://www.msen.com/~clif/TclTutor.html
COMMENT=	Learn Tcl interactively
LICENSE=	isc

WRKSRC=		${WRKDIR}/TclTutor

SUBST_CLASSES+=		fix-wish
SUBST_STAGE.fix-wish=	pre-configure
SUBST_MESSAGE.fix-wish=	Fixing tcl wish
SUBST_FILES.fix-wish+=	TclTutor.tcl
SUBST_SED.fix-wish+=	-e 's,exec wish,exec ${PREFIX}/bin/wish,'

SUBST_CLASSES+=		fix-data
SUBST_STAGE.fix-data=	pre-configure
SUBST_MESSAGE.fix-data=	Fixing libdatadir
SUBST_FILES.fix-data+=	TclTutor.tcl
SUBST_SED.fix-data+=	-e 's,@TCLTUTOR_LIBDATADIR@,${PREFIX}/${TCLTUTOR_LIBDATADIR},'

NO_BUILD=	yes

USE_TOOLS+=	pax:build wish:run

TCLTUTOR_LIBDATADIR=	share/tcltutor
TCLTUTOR_DOCDIR=	share/doc/tcltutor

INSTALLATION_DIRS+=	bin ${TCLTUTOR_LIBDATADIR} ${TCLTUTOR_DOCDIR}

pre-configure:
	${RUN} cd ${WRKSRC} && ${FIND} . -type d -name 'CVS' | ${XARGS} ${RM} -fr

do-install:
	${RUN} cd ${WRKSRC} && \
		${INSTALL_SCRIPT} TclTutor.tcl ${DESTDIR}${PREFIX}/bin/tcltutor
.for i in balloon.tcl htmllib.tcl images.tcl options.tcl simpleTop.tcl
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA} ${i} ${DESTDIR}${PREFIX}/${TCLTUTOR_LIBDATADIR}
.endfor
.for i in NOTICE README
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA} ${i} ${DESTDIR}${PREFIX}/${TCLTUTOR_DOCDIR}
.endfor
.for i in Tcl_English Tcl_Portuguese
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${TCLTUTOR_LIBDATADIR}/lesson/${i}
	${RUN} cd ${WRKSRC}/lesson/${i} && \
		${PAX} -wr *  ${DESTDIR}${PREFIX}/${TCLTUTOR_LIBDATADIR}/lesson/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
