# $NetBSD: Makefile,v 1.3 2001/02/17 18:09:26 wiz Exp $
#

DISTNAME=	tds-1.3.2
CATEGORIES=	misc www
MASTER_SITES=	http://www.morito.mgmt.waseda.ac.jp/~tom/TomSoft/TsDiary/dist/current/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.morito.mgmt.waseda.ac.jp/~tom/TomSoft/TsDiary/
COMMENT=	web diary system

USE_PERL=	YES
GNU_CONFIGURE=	YES

NO_BUILD=	YES

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' | xargs ${RM} -f

.include "../../mk/bsd.pkg.mk"
