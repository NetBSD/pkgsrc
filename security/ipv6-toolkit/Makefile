# $NetBSD: Makefile,v 1.11 2026/07/16 19:04:39 wiz Exp $

DISTNAME=	ipv6toolkit-2.2
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fgont/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	http://www.si6networks.com/tools/ipv6toolkit
COMMENT=	IPv6 security assessment and troubleshooting tool
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	perl

REPLACE_PERL+=	tools/blackhole6 tools/script6 tools/messi

post-install:
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7

	${INSTALL_MAN} ${WRKSRC}/manuals/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/manuals/*.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/manuals/*.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/


.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
