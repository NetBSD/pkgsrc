# $NetBSD: Makefile,v 1.5 2001/11/28 17:30:38 wiz Exp $

DISTNAME=	micq-0.4.7
CATEGORIES=	chat
MASTER_SITES=	http://micq.ukeer.de/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://micq.ukeer.de/
COMMENT=	text-mode ICQ client

USE_GMAKE=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/micq.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/micq.7 ${PREFIX}/man/man7
	${INSTALL_MAN} ${WRKSRC}/doc/micqrc.5 ${PREFIX}/man/man5

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
