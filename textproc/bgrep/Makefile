# $NetBSD: Makefile,v 1.1.1.1 2003/08/25 11:13:00 cjep Exp $
#

DISTNAME=	bgrep-20030825
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD othersrc

CONFLICTS+=		bsdgrep-*
#ONLY_FOR_PLATFORM=	NetBSD-1.6*-*

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
