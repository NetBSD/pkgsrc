# $NetBSD: Makefile,v 1.11 2005/12/26 23:39:33 schmonz Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Anonymize tcpdump traces

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
