# $NetBSD: Makefile,v 1.2 1999/06/08 09:52:19 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/17 10:56:40 vanilla Exp $

DISTNAME=	jcode.pl-2.10
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${PREFIX}/lib/perl5/site_perl/jcode.pl

.include "../../mk/bsd.pkg.mk"
