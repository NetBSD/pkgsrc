# $NetBSD: Makefile,v 1.8 2012/10/03 00:02:45 asau Exp $
#

# TODO: gnupg support, ssl support, others

DISTNAME=	tkabber-0.11.1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://files.jabber.ru/tkabber/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tkabber.jabber.ru/en/
COMMENT=	Free and Open Source TCL/TK jabber client

DEPENDS+=	tcllib-[0-9]*:../../devel/tcllib

USE_TOOLS+=	pax wish:run

EGDIR=		${PREFIX}/share/examples/tkabber
DATADIR=	${PREFIX}/share/tkabber
DOCDIR=		${PREFIX}/share/doc/tkabber

AUTO_MKDIRS=		yes

# XXX this is also in the tkabber's Makefile
SUBDIRS=	emoticons \
		ifacetk	  \
		jabberlib \
		tclxml    \
		mclistbox \
		msgs	  \
		pixmaps	  \
		plugins	  \
		sounds	  \
		trans

EXTRA_FILES=	AUTHORS README COPYING INSTALL ChangeLog

do-build:
	    # TODO This must be a CLASS
	    ${SED} -e "s,@WISH@,${WISH}," \
		    -e "s,@DATADIR@,${DATADIR}," ${FILESDIR}/tkabber.sh \
		    > ${WRKSRC}/tkabber

do-install:
	   ${INSTALL_DATA} ${WRKSRC}/*.tcl ${DESTDIR}${DATADIR} #${WRKSRC}/*.xrdb ${DATADIR}
	   cd ${WRKSRC} && ${INSTALL_DATA} ${EXTRA_FILES} ${DESTDIR}${DOCDIR}
	   cd ${WRKSRC}/examples && pax -rw -pm . ${DESTDIR}${EGDIR}
.for i in ${SUBDIRS}
	   cd ${WRKSRC} && pax -rw -pm ${i} ${DESTDIR}${DATADIR}
.endfor
	   ${INSTALL_SCRIPT} ${WRKSRC}/tkabber ${DESTDIR}${PREFIX}/bin

.include "../../x11/tk-BWidget/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
