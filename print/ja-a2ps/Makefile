# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:01:03 seb Exp $
# FreeBSD Id: Makefile,v 1.5 1999/04/16 04:57:06 taoka Exp $

DISTNAME=	a2ps.pl-1.44
PKGNAME=	ja-a2ps-1.44
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# None

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Text file to postscript converter (with Japanese support)

USE_PERL5=	YES

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .
WRKSRC=		${WRKDIR}
NO_BUILD=	yes
REPLACE_PERL=	a2ps.pl-1.44

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps.pl-1.44 ${PREFIX}/bin/a2ps-j

.include "../../mk/bsd.pkg.mk"
