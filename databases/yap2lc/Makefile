# $NetBSD: Makefile,v 1.4 2008/09/06 20:54:32 wiz Exp $

DISTNAME=	yap2lc-0.5.9
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yap2lc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/yap2lc/
COMMENT=	Yet Another Passwd 2 LDIF Converter

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	bin share/doc/yap2lc share/examples/yap2lc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yap2lc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/yap2lc
	${INSTALL_DATA} ${WRKSRC}/samples/ldif.template \
	  ${DESTDIR}${PREFIX}/share/examples/yap2lc
	${INSTALL_DATA} ${WRKSRC}/samples/yap2lc.conf \
	  ${DESTDIR}${PREFIX}/share/examples/yap2lc

.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
