# $NetBSD: Makefile,v 1.12 2001/02/16 14:38:41 wiz Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/16 08:22:35 max Exp
#

DISTNAME=       m4-1.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=m4/}

MAINTAINER=	packages@netbsd.org
COMMENT=	GNU version of Unix m4 macro-processor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g
INFO_FILES=	m4.info

post-install:
	@${MKDIR} ${PREFIX}/share/examples/gm4
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${PREFIX}/share/examples/gm4

.include "../../mk/bsd.pkg.mk"
