# $NetBSD: Makefile,v 1.13 2003/09/28 21:08:59 sjg Exp $
#

DISTNAME=	mk-20030928
PKGNAME=	mk-files-20030928
WRKSRC=		${WRKDIR}/mk
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.NetBSD.org/pub/incoming/sjg/

MAINTAINER=	sjg@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable *.mk files for the NetBSD portable bmake utility

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=${WRKDIR}/.PLIST_SRC

do-install:
	${WRKSRC}/install-mk ${PREFIX}/share/mk

.include "../../mk/bsd.pkg.mk"

# The logic below mimics what install-mk does.
# Ie. it won't install a sys.mk if a standard BSD one exists
# same goes for the bsd.*.mk files (it makes the symlinks to *.mk)
${WRKSRC}/FILES:	extract
${WRKDIR}/.PLIST_SRC:	${WRKSRC}/FILES
	@( ${GREP} '^[a-z].*\.mk' $> ; \
	[ -f /usr/share/mk/sys.mk ] || ${ECHO} sys.mk; \
	[ -f /usr/share/mk/bsd.prog.mk ] || \
	for f in dep doc init lib man nls obj own prog subdir; do \
		${ECHO} bsd.$$f.mk; \
	done ) | ${SED} 's,^,share/mk/,' > $@
