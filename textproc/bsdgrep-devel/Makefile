# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:19 tv Exp $
#

DISTNAME=	bsdgrep-200405051607
PKGNAME=	bsdgrep-devel-20040505
PKGREVISION=	1
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD src/usr.bin/grep

USE_BUILDLINK3=	yes

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
