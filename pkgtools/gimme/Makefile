# $NetBSD: Makefile,v 1.2 2017/02/13 09:36:04 jperkin Exp $

DISTNAME=		gimme-20170213
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Script to make binary packages in a chroot
LICENSE=		modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-*

DEPENDS+=		pkg_comp1>=1.38nb1:../../pkgtools/pkg_comp1

AUTO_MKDIRS=		yes

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	@${ECHO} "Build done"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gimme.sh ${DESTDIR}${PREFIX}/bin/gimme
	${INSTALL_MAN} ${WRKSRC}/gimme.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gimme.1

.include "../../mk/bsd.pkg.mk"
