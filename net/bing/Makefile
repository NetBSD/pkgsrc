# $NetBSD: Makefile,v 1.6 1998/06/22 12:58:34 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/10/13 09:14:49 tg Exp
#

DISTNAME=	bing-1.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibp.fr/pub/networking/

MAINTAINER=	packages@netbsd.org

.include "../../mk/bsd.prefs.mk"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/bing
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/bing
.endif

.include "../../mk/bsd.pkg.mk"
