# $NetBSD: Makefile,v 1.40 2020/02/19 14:33:00 gdt Exp $

DISTNAME=	slib-3b6
#
# Convert the version number as follows 2d2 -> 2.4.2, where the d is
# changed to a 4, representing the 4th letter.
# Thus, 3a1 -> 3.1.1
#
# Also update guile-slib
#
PKGNAME=	slib-3.2.6
CATEGORIES=	devel
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.csail.mit.edu/jaffer/SLIB.html
COMMENT=	Portable Scheme library of compatibility and utility functions

#LICENSE=	TODO: many licenses, all either PD or acceptable, in theory

NO_CONFIGURE=	yes
NO_BUILD=	yes

SLIBDIR=	${PREFIX}/share/slib
DOCDIR=		${PREFIX}/share/doc/slib
INFO_FILES=	yes

INSTALLATION_DIRS=	${PKGINFODIR} share/slib share/doc/slib

SUBST_CLASSES+=		scmpath
SUBST_STAGE.scmpath=	pre-configure
SUBST_FILES.scmpath=	guile.init
SUBST_SED.scmpath=	-e "s|/usr/share/slib|${PREFIX}/share/slib|"

do-install:
	# symlink is a workaround for guile-slib with guile20-2.0.12
	# remove when not needed any longer
	cd ${DESTDIR}${SLIBDIR} && ${LN} -s . slib
	cd ${WRKSRC}; ${INSTALL_DATA} *.scm *.init ${DESTDIR}${SLIBDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README FAQ ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}; for f in slib.info slib.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done

.include "../../mk/bsd.pkg.mk"
