# $NetBSD: Makefile,v 1.18 2022/06/28 11:35:22 wiz Exp $

DISTNAME=		slrn-1.0.3a
PKGNAME=		cleanscore-0.9.8.1
PKGREVISION=		13
CATEGORIES=		news
MASTER_SITES=		http://jedsoft.org/releases/slrn/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://slrn.sourceforge.net/
COMMENT=		Clean SLRN's score file
LICENSE=		gnu-gpl-v2

EXTRACT_USING=		bsdtar
USE_TOOLS=		perl
REPLACE_PERL=		contrib/cleanscore

WRKSRC=			${WRKDIR}/slrn-1.0.3

NO_BUILD=		yes

INSTALLATION_DIRS+=	bin share/doc/cleanscore

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cleanscore ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/contrib/README.cleanscore ${DESTDIR}${PREFIX}/share/doc/cleanscore
	${INSTALL_DATA} ${WRKSRC}/contrib/NEWS.cleanscore ${DESTDIR}${PREFIX}/share/doc/cleanscore

.include "../../mk/bsd.pkg.mk"
