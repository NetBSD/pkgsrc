# $NetBSD: Makefile,v 1.1.1.1 2000/03/07 19:03:59 jlam Exp $

DISTNAME=		doc++-3.3.13
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/doctools/} \
			http://zeus.imaginator.com/doc++/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.imaginator.com/doc++/

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/doc++
	${INSTALL_DATA} ${WRKSRC}/doc/manual/html/* ${PREFIX}/share/doc/doc++

.include "../../mk/bsd.pkg.mk"
