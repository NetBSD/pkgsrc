# $NetBSD: Makefile,v 1.6 2004/01/02 15:10:06 cjep Exp $
#

DISTNAME=	bsdgrep-200312301530
PKGNAME=	bsdgrep-devel-20031230
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD src/usr.bin/grep

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
