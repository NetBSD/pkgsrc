# $NetBSD: Makefile,v 1.5 2002/09/20 07:00:56 sjg Exp $
#

DISTNAME=	mk-1.3.2
PKGNAME=	mk-files-1.3.2
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.netbsd.org/pub/incoming/sjg/

MAINTAINER=	sjg@netbsd.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	portable *.mk files for the NetBSD portable bmake utility

WRKSRC=		${WRKDIR}/mk

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
	@( grep '^[a-z].*\.mk' $> ; \
	[ -f /usr/share/mk/sys.mk ] || echo sys.mk; \
	[ -f /usr/share/mk/bsd.prog.mk ] || \
	for f in dep doc init lib man nls obj own prog subdir; do \
		echo bsd.$$f.mk; \
	done ) | sed 's,^,share/mk/,' > $@
