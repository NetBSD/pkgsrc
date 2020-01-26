# $NetBSD: Makefile,v 1.13 2020/01/26 17:31:59 rillig Exp $

PKGNAME=	genrpm-1.2
CATEGORIES=	pkgtools

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Generate an RPM package from an installed pkgsrc package
LICENSE=	modified-bsd

DEPENDS+=	pkg_tarup-[0-9]*:../../pkgtools/pkg_tarup
DEPENDS+=	rpm-[0-9]*:../../misc/rpm

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.prefs.mk"

do-build:
	@for f in genrpm genrpm.8 genrpm.0; do				\
		${SED} -e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'		\
			-e 's|@SH@|${SH}|g'				\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;		\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/genrpm ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/genrpm.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
