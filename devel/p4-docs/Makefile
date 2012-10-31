# $NetBSD: Makefile,v 1.12 2012/10/31 11:17:34 asau Exp $
#

DISTNAME=	p4-docs
COMMENT=	Perforce SCM documentation

.include "../../devel/p4/Makefile.common"

# override, since the docs have changed at least once more often
# than the binaries for NetBSD
DIST_SUBDIR=	perforce-20070118

HOMEPAGE=	http://www.perforce.com/perforce/technical.html

DISTFILES=	p4.1
DISTFILES+=	p4d.1
DISTFILES+=	relnotes.txt
DISTFILES+=	platformnotes.html
DISTFILES+=	cmdref.pdf
DISTFILES+=	p4ftp.pdf
DISTFILES+=	p4guide.pdf
DISTFILES+=	p4sag.pdf

P4_DOCURL_PREFIX=		http://www.perforce.com/perforce/doc.062
P4_MANURL_PREFIX=		http://www.perforce.com/perforce/doc.052

SITES.p4.1=			${P4_MANURL_PREFIX}/man/
SITES.p4d.1=			${P4_MANURL_PREFIX}/man/
SITES.relnotes.txt=		${P4_DOCURL_PREFIX}/user/
SITES.platformnotes.html=	${P4_DOCURL_PREFIX}/user/
SITES.cmdref.pdf=		${P4_DOCURL_PREFIX}/manuals/cmdref/
SITES.p4ftp.pdf=		${P4_DOCURL_PREFIX}/manuals/p4ftp/
SITES.p4guide.pdf=		${P4_DOCURL_PREFIX}/manuals/p4guide/
SITES.p4sag.pdf=		${P4_DOCURL_PREFIX}/manuals/p4sag/

DOCDIR=		share/doc/p4
PLIST_SUBST+=	DOCDIR=${DOCDIR:Q}

INSTALLATION_DIRS=	${DOCDIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/*.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

	cd ${WRKSRC};							\
	for f in *.html *.pdf *.txt; do					\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/${DOCDIR};	\
	done

.include "../../mk/bsd.pkg.mk"
