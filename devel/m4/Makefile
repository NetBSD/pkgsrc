# $NetBSD: Makefile,v 1.11 1999/04/14 21:39:02 tron Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/16 08:22:35 max Exp
#

DISTNAME=       m4-1.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=m4/}

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g
INFO_FILES=	m4.info

post-install:
	@${MKDIR} ${PREFIX}/share/examples/gm4
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${PREFIX}/share/examples/gm4

.include "../../mk/bsd.pkg.mk"
