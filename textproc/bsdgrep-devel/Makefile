# $NetBSD: Makefile,v 1.5 2003/12/30 15:34:52 cjep Exp $
#

DISTNAME=	bsdgrep-200312301530
PKGNAME=	bsdgrep-devel-20031230
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD othersrc

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
