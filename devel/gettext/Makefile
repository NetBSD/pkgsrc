# $NetBSD: Makefile,v 1.14 2000/06/30 17:07:35 danw Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.10.35
PKGNAME=		gettext-0.10.35nb1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INFO_FILES=		gettext.info

.include "../../mk/bsd.prefs.mk"

# The install target in intl/Makefile has a comment whereby libintl.a
# and libintl.h should not be installed on systems which have gettext()
# function in their libc

.if ${OPSYS} == "SunOS"
PLIST_SRC=      	${WRKDIR}/PLIST-src

pre-install:
	@${SED} -e '/^include\/libintl\.h$$/d' -e '/^lib\/libintl\.a$$/d' \
		${PKGDIR}/PLIST > ${PLIST_SRC}
.endif # SunOS

.include "../../mk/bsd.pkg.mk"
