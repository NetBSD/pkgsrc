# $NetBSD: Makefile,v 1.2 1999/06/07 07:18:37 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.5 1999/04/16 04:57:06 taoka Exp $

DISTNAME=	a2ps.pl-1.44
PKGNAME=	ja-a2ps-1.44
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# None

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

USE_PERL5=	YES

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps.pl-1.44 ${PREFIX}/bin/a2ps-j

.include "../../mk/bsd.pkg.mk"
