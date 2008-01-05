# $NetBSD: Makefile,v 1.22 2008/01/05 21:48:53 rillig Exp $
#

DISTNAME=	mk-20050405
PKGNAME=	mk-files-20050405
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/

CONFLICTS+=	bootstrap-mk-files-[0-9]*

MAINTAINER=	sjg@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable *.mk files for the NetBSD portable bmake utility

NO_CONFIGURE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/mk

.include "../../mk/bsd.prefs.mk"

.if ${PKGSRC_LOCKTYPE} == sleep
PKG_FAIL_REASON=	"Recurses against itself"
.endif


PLIST_SRC=${WRKDIR}/.PLIST_SRC

do-install:
	${WRKSRC}/install-mk ${PREFIX}/share/mk

.include "../../mk/bsd.pkg.mk"

# The logic below mimics what install-mk does.
# Ie. it won't install a sys.mk if a standard BSD one exists
# same goes for the bsd.*.mk files (it makes the symlinks to *.mk)
${WRKSRC}/FILES:	extract
${WRKDIR}/.PLIST_SRC:	${WRKSRC}/FILES
	@( ${GREP} '^[A-Za-z].*\.mk' ${.ALLSRC} ; \
	[ -f /usr/share/mk/sys.mk ] || ${ECHO} sys.mk; \
	[ -f /usr/share/mk/bsd.prog.mk ] || \
	for f in dep doc init lib man nls obj own prog subdir; do \
		${ECHO} bsd.$$f.mk; \
	done ) | ${SED} 's,^,share/mk/,' > ${.TARGET}
