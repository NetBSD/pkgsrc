# $NetBSD: Makefile,v 1.11 1999/05/23 19:48:46 tv Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=	gettext-0.10.35
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/gnu/

MAINTAINER=	tron@netbsd.org

GNU_CONFIGURE=	yes

INFO_FILES=	gettext.info

.include "../../mk/bsd.prefs.mk"

# The install target in intl/Makefile has a comment whereby libintl.a
# and libintl.h should not be installed on systems which have gettext()
# function in their libc

.if ${OPSYS} == "SunOS"
PLIST_SRC=      ${WRKDIR}/PLIST-src

pre-install:
	@${SED} -e '/^include\/libintl\.h$$/d' -e '/^lib\/libintl\.a$$/d' \
		${PKGDIR}/PLIST > ${PLIST_SRC}
.endif # SunOS

.include "../../mk/bsd.pkg.mk"
