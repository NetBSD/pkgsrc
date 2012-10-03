# $NetBSD: Makefile,v 1.12 2012/10/03 21:57:18 wiz Exp $

DISTNAME=	a2ps.pl-1.45
PKGNAME=	ja-a2ps-1.45
PKGREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# None

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.srekcah.org/~utashiro/perl/scripts/a2ps_pl/
COMMENT=	Text file to postscript converter (with Japanese support)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run

NO_BUILD=	yes
REPLACE_PERL=	a2ps.pl-1.45

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps.pl-1.45 ${DESTDIR}${PREFIX}/bin/a2ps-j

.include "../../mk/bsd.pkg.mk"
