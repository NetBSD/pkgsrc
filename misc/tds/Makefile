# $NetBSD: Makefile,v 1.12 2005/12/05 20:50:40 rillig Exp $
#

DISTNAME=	tds-1.4.2
PKGREVISION=	1
CATEGORIES=	misc www japanese
MASTER_SITES=	http://tds.dive-in.to/dist/stable/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://tds.dive-in.to/
COMMENT=	Web diary system

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PERL5=${PERL5:Q}

NO_BUILD=	YES

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../mk/bsd.pkg.mk"
