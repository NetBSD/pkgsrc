# $NetBSD: Makefile,v 1.33 2023/11/07 08:07:11 fcambus Exp $

DISTNAME=	console-setup_1.223
PKGNAME=	bdf2psf-1.223
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/c/console-setup/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/sid/bdf2psf
COMMENT=	Convert a BDF font to PSF format for the Linux console
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/console-setup-${PKGVERSION_NOREV}

USE_TOOLS+=	perl:run

NO_BUILD=	yes

REPLACE_PERL+=	Fonts/${PKGBASE}

SHAREDIR=	${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${SHAREDIR}/fontsets

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Fonts/${PKGBASE} ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PKGBASE}.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/Fonts/*.equivalents ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/Fonts/*.set ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/Fonts/fontsets/* \
		${DESTDIR}${SHAREDIR}/fontsets

.include "../../mk/bsd.pkg.mk"
