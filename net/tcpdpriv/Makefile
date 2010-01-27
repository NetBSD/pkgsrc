# $NetBSD: Makefile,v 1.16 2010/01/27 17:44:37 joerg Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Anonymize tcpdump traces

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
