# $NetBSD: Makefile,v 1.1.1.1 2005/04/20 09:36:00 agc Exp $

DISTNAME=	genrpm-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Generate an RPM package from an installed pkgsrc package

DEPENDS+=	pkg_tarup-[0-9]*:../../pkgtools/pkg_tarup
DEPENDS+=	rpm-[0-9]*:../../misc/rpm

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes

INSTALLATION_DIRS=	man/cat8 man/man8 sbin

.include "../../mk/bsd.prefs.mk"

do-build:
	@for f in genrpm genrpm.8 genrpm.0; do				\
		${SED} -e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'		\
			-e 's|@SH@|${SH}|g'				\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;		\
	done
.if ${OPSYS} == "SunOS" || ${OPSYS} == "AIX"
	# pre-created man-pages are "mandoc" pages, these OS need "man",
	# so regen the .0 page
	nroff -man ${WRKSRC}/genrpm.8 >${WRKSRC}/genrpm.0
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/genrpm ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/genrpm.0 ${PREFIX}/man/cat8
	${INSTALL_MAN} ${WRKSRC}/genrpm.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
