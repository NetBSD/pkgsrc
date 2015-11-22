# $NetBSD: Makefile,v 1.1.1.1 2015/11/22 21:57:38 agc Exp $

DISTNAME=		gimme-20151122
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Script to make binary packages in a chroot
LICENSE=		modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-*

DEPENDS+=		pkg_comp>=1.38nb1:../../pkgtools/pkg_comp

AUTO_MKDIRS=		yes

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	@${ECHO} "Build done"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gimme.sh ${DESTDIR}${PREFIX}/bin/gimme
	${INSTALL_MAN} ${WRKSRC}/gimme.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gimme.1

.include "../../mk/bsd.pkg.mk"
