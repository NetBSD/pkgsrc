# $NetBSD: Makefile,v 1.25 2022/06/28 11:35:29 wiz Exp $

DISTNAME=	a2ps.pl-1.45
PKGNAME=	ja-a2ps-1.45
PKGREVISION=	12
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# None

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.srekcah.org/~utashiro/perl/scripts/a2ps_pl/
COMMENT=	Text file to postscript converter (with Japanese support)
LICENSE=	mit

DEPENDS+=	nkf-[0-9]*:../../converters/nkf

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run

NO_BUILD=	yes
REPLACE_PERL=	a2ps.pl-1.45

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps.pl-1.45 ${DESTDIR}${PREFIX}/bin/a2ps-j

.include "../../mk/bsd.pkg.mk"
