# $NetBSD: Makefile,v 1.5 2001/05/12 16:06:25 wiz Exp $
#

DISTNAME=	tds-1.4.2
CATEGORIES=	misc www japanese
MASTER_SITES=	http://tds.dive-in.to/dist/stable/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://tds.dive-in.to/
COMMENT=	web diary system

USE_PERL5=	YES
GNU_CONFIGURE=	YES

NO_BUILD=	YES

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' | xargs ${RM} -f

.include "../../mk/bsd.pkg.mk"
