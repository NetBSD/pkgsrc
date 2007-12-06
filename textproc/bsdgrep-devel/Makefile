# $NetBSD: Makefile,v 1.13 2007/12/06 21:43:19 cjep Exp $
#

DISTNAME=	bsdgrep-20071201
PKGNAME=	bsdgrep-devel-20071201
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD src/usr.bin/grep

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP}

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
