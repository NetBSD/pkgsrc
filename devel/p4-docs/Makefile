# $NetBSD: Makefile,v 1.4 2005/06/16 06:57:47 jlam Exp $
#

DISTNAME=	p4-docs
PKGREVISION=	1
COMMENT=	Perforce SCM documentation

.include "../../devel/p4/Makefile.common"

# override, since the docs have changed at least once more often
# than the binaries for NetBSD
DIST_SUBDIR=	perforce-20040716

HOMEPAGE=	http://www.perforce.com/perforce/technical.html

DISTFILES=	p4.1
DISTFILES+=	p4d.1
DISTFILES+=	relnotes.txt
DISTFILES+=	platformnotes.html
DISTFILES+=	cmdref_html.zip
DISTFILES+=	p4ftp_html.zip
DISTFILES+=	p4guide_html.zip
DISTFILES+=	p4sag_html.zip

P4_DOCURL_PREFIX=		http://www.perforce.com/perforce/doc.021

SITES_p4.1=			${P4_DOCURL_PREFIX}/man/
SITES_p4d.1=			${P4_DOCURL_PREFIX}/man/
SITES_relnotes.txt=		${P4_DOCURL_PREFIX}/user/
SITES_platformnotes.html=	${P4_DOCURL_PREFIX}/user/
SITES_cmdref_html.zip=		${P4_DOCURL_PREFIX}/manuals/cmdref/
SITES_p4ftp_html.zip=		${P4_DOCURL_PREFIX}/manuals/p4ftp/
SITES_p4guide_html.zip=		${P4_DOCURL_PREFIX}/manuals/p4guide/
SITES_p4sag_html.zip=		${P4_DOCURL_PREFIX}/manuals/p4sag/

EXTRACT_ONLY=		cmdref_html.zip p4ftp_html.zip
EXTRACT_ONLY+=		p4guide_html.zip p4sag_html.zip
EXTRACT_CMD.zip=	${LOCALBASE}/bin/unzip -Laq $${extract_file} \
			-d `${BASENAME} $${extract_file} _html.zip`

DOCDIR=		share/doc/p4
HTMLDIR=	share/doc/html/p4
PLIST_SUBST+=	DOCDIR=${DOCDIR}
PLIST_SUBST+=	HTMLDIR=${HTMLDIR}

INSTALLATION_DIRS=	man/man1

do-install:
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/*.1 ${PREFIX}/man/man1

	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/relnotes.txt \
		${PREFIX}/${DOCDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/platformnotes.html \
		${PREFIX}/${HTMLDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}/cmdref
	${INSTALL_DATA} ${WRKSRC}/cmdref/* ${PREFIX}/${HTMLDIR}/cmdref

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}/p4ftp
	${INSTALL_DATA} ${WRKSRC}/p4ftp/* ${PREFIX}/${HTMLDIR}/p4ftp

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}/p4guide
	${INSTALL_DATA} ${WRKSRC}/p4guide/* ${PREFIX}/${HTMLDIR}/p4guide

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}/p4sag
	${INSTALL_DATA} ${WRKSRC}/p4sag/* ${PREFIX}/${HTMLDIR}/p4sag

.include "../../mk/bsd.pkg.mk"
