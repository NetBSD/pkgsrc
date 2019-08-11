# $NetBSD: Makefile,v 1.21 2019/08/11 13:22:40 wiz Exp $

DISTNAME=	a2ps.pl-1.45
PKGNAME=	ja-a2ps-1.45
PKGREVISION=	8
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# None
LICENSE=	mit

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
#HOMEPAGE=	http://www.srekcah.org/~utashiro/perl/scripts/a2ps_pl/
COMMENT=	Text file to postscript converter (with Japanese support)

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run

NO_BUILD=	yes
REPLACE_PERL=	a2ps.pl-1.45

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps.pl-1.45 ${DESTDIR}${PREFIX}/bin/a2ps-j

.include "../../mk/bsd.pkg.mk"
