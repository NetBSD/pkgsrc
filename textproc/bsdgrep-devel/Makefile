# $NetBSD: Makefile,v 1.4 2003/09/14 15:15:17 cjep Exp $
#

DISTNAME=	bsdgrep-200309141607
PKGNAME=	bsdgrep-devel-20030914
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD othersrc

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
