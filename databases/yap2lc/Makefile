# $NetBSD: Makefile,v 1.6 2010/09/16 08:06:14 adam Exp $

DISTNAME=	yap2lc-0.5.9
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yap2lc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/yap2lc/
COMMENT=	Yet Another Passwd 2 LDIF Converter

PKG_DESTDIR_SUPPORT=	user-destdir

BDB_ACCEPTED=		db4 db5
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		BDB_TYPE="${BDB_TYPE}"

INSTALLATION_DIRS=	bin share/doc/yap2lc share/examples/yap2lc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yap2lc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/yap2lc
	${INSTALL_DATA} ${WRKSRC}/samples/ldif.template \
		${DESTDIR}${PREFIX}/share/examples/yap2lc
	${INSTALL_DATA} ${WRKSRC}/samples/yap2lc.conf \
		${DESTDIR}${PREFIX}/share/examples/yap2lc

BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
