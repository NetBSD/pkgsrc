# $NetBSD: Makefile,v 1.15 2001/10/19 09:13:29 veego Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/16 08:22:35 max Exp
#

DISTNAME=       m4-1.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=m4/}

MAINTAINER=	packages@netbsd.org
COMMENT=	GNU version of Unix m4 macro-processor

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--program-prefix=g
INFO_FILES=		m4.info

pre-build:
	${CHMOD} u+w ${WRKSRC}/checks/stamp-checks

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gm4
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${PREFIX}/share/examples/gm4

.include "../../mk/bsd.pkg.mk"
