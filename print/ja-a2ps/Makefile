# $NetBSD: Makefile,v 1.4 2003/07/17 22:52:30 grant Exp $
# FreeBSD Id: Makefile,v 1.5 1999/04/16 04:57:06 taoka Exp $

DISTNAME=	a2ps.pl-1.45
PKGNAME=	ja-a2ps-1.45
WRKSRC=		${WRKDIR}
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# None

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Text file to postscript converter (with Japanese support)

USE_PERL5=	YES

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .
NO_BUILD=	yes
REPLACE_PERL=	a2ps.pl-1.45

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps.pl-1.45 ${PREFIX}/bin/a2ps-j

.include "../../mk/bsd.pkg.mk"
