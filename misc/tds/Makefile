# $NetBSD: Makefile,v 1.10 2005/07/08 20:27:05 kristerw Exp $
#

DISTNAME=	tds-1.4.2
PKGREVISION=	1
CATEGORIES=	misc www japanese
MASTER_SITES=	http://tds.dive-in.to/dist/stable/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://tds.dive-in.to/
COMMENT=	Web diary system

USE_PERL5=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PERL5="${PERL5}"

NO_BUILD=	YES

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../mk/bsd.pkg.mk"
