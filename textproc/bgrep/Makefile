# $NetBSD: Makefile,v 1.2 2003/08/27 18:32:46 jmc Exp $
#

DISTNAME=	bgrep-20030825
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD othersrc

WRKSRC=		${WRKDIR}/nbgrep-20030825
CONFLICTS+=		bsdgrep-*
#ONLY_FOR_PLATFORM=	NetBSD-1.6*-*

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
