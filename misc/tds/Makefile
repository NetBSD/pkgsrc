# $NetBSD: Makefile,v 1.8 2003/07/21 17:01:27 martti Exp $
#

DISTNAME=	tds-1.4.2
CATEGORIES=	misc www japanese
MASTER_SITES=	http://tds.dive-in.to/dist/stable/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://tds.dive-in.to/
COMMENT=	Web diary system

USE_PERL5=	YES
GNU_CONFIGURE=	YES

NO_BUILD=	YES

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' | ${XARGS} ${RM} -f

.include "../../mk/bsd.pkg.mk"
