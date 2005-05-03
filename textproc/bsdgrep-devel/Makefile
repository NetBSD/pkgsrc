# $NetBSD: Makefile,v 1.11 2005/05/03 21:42:53 kristerw Exp $
#

DISTNAME=	bsdgrep-200405051607
PKGNAME=	bsdgrep-devel-20040505
PKGREVISION=	2
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD src/usr.bin/grep

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
