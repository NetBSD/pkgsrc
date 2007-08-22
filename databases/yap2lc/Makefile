# $NetBSD: Makefile,v 1.1.1.1 2007/08/22 17:32:07 tron Exp $

DISTNAME=	yap2lc-0.5.9
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yap2lc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/yap2lc/
COMMENT=	Yet Another Passwd 2 LDIF Converter

GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	bin share/doc/yap2lc share/examples/yap2lc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yap2lc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/yap2lc
	${INSTALL_DATA} ${WRKSRC}/samples/ldif.template \
	  ${PREFIX}/share/examples/yap2lc
	${INSTALL_DATA} ${WRKSRC}/samples/yap2lc.conf \
	  ${PREFIX}/share/examples/yap2lc

.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
