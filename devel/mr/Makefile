# $NetBSD: Makefile,v 1.5 2012/01/08 02:41:35 schmonz Exp $
#

DISTNAME=		mr_1.10
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/m/mr/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://kitenet.net/~joey/code/mr/
COMMENT=		Treat multiple repositories as one combined repository
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

NO_BUILD=		yes

WRKSRC=			${WRKDIR}/${PKGBASE}
USE_LANGUAGES=		# none

USE_TOOLS+=		perl:run

REPLACE_PERL+=  	mr webcheckout

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
SHAREDIR=		${PREFIX}/share/${PKGBASE}
INSTALLATION_DIRS=	bin ${EGDIR} ${SHAREDIR}

do-install:
	set -e; cd ${WRKSRC};						\
	${INSTALL_DATA} mrconfig ${DESTDIR}${EGDIR};			\
	${INSTALL_DATA} mrconfig.complex ${DESTDIR}${EGDIR};		\
	for i in lib/*; do						\
	${INSTALL_DATA} $${i} ${DESTDIR}${SHAREDIR};			\
	done;								\
	${INSTALL_SCRIPT} mr ${DESTDIR}${PREFIX}/bin;			\
	${INSTALL_SCRIPT} webcheckout ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
